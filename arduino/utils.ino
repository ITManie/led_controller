/**
 * IQRF timer
 * @param none
 * @return none
 */
void cb_timer1ms() {
  if (iqrf.appTimer && (--iqrf.appTimer) == 0) {
    iqrf.appTimerAck = 1;
    iqrf.appTimer = USER_TIMER_PERIOD;
  }
}

/**
 * Check address from packet and address of controller
 * @param buf[] IQRF Rx buffer
 * @return true or false
 */
boolean isMyAddress(uint8_t buf[] = iqrf.RxBuf) {
  uint8_t addr[4] = {buf[2], buf[3], buf[4], buf[5]};
  return addr == my_addr ? true : false;
}

/**
 * Recieve ping packet and call function sendPong
 * @param none
 * @return none
 */
void receivePing() {
  if (isMyAddress()) {
    sendPong(my_addr, iqrf.TxBuf);
  }
}

/**
 * Send pong packet (answer on the ping packet)
 * @param addr[] Address of this controller (defined in my_addr)
 * @param buf[] IQRF Tx buffer
 * @return none
 */
void sendPong(uint8_t addr[], uint8_t buf[]) {
  uint8_t packet[6] = {0, 1, addr[0], addr[1], addr[2], addr[3]};
  if (iqrf.appTimerAck) {
    buf = (uint8_t *)malloc(sizeof(packet));
    if (buf != NULL) {
      memcpy(buf, (uint8_t *)&packet, sizeof(packet));
      iqrf.testPktId = IQRF_SendData(buf, sizeof(packet), 1);
    }
    iqrf.appTimerAck = 0;
  }
}

/**
 * Get data from set color packet and set color of RGB lED
 * @param buf[] IQRF Rx buffer
 * @return none
 */
void setColor(uint8_t buf[] = iqrf.RxBuf) {
  uint8_t red_value = buf[6];
  uint8_t green_value = buf[7];
  uint8_t blue_value = buf[8];
  uint8_t alpha_value = buf[9];
  if (isMyAddress() && alpha_value == 0x00) {
    analogWrite(red_led, red_value);
    analogWrite(green_led, green_value);
    analogWrite(blue_led, blue_value);
  }
}

/**
 * IQRF Rx handler
 * @param none
 * @return none
 */
void IqrfRx() {
  IQRF_GetRxData(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.print("IQRF receive done: ");
  Serial.write(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.println();
  uint8_t prot_version = iqrf.RxBuf[0];
  if (prot_version == 0x00) {
    uint8_t prot_type = iqrf.RxBuf[1];
    switch (prot_type) {
      case 0x00:
        receivePing();
        break;
      case 0x02:
        setColor();
        break;
    }
  }
}

/**
 * IQRF Tx gandler
 * @param txPktId
 * @param txPktResult
 * @return none
 */
void IqrfTx(uint8_t txPktId, uint8_t txPktResult) {
  Serial.println("IQRF send done");
}

