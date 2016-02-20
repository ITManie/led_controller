void AppTimerHandler();

void cb_timer1ms() {
  if (iqrf.appTimer && (--iqrf.appTimer) == 0) {
    AppTimerHandler();
    iqrf.appTimer = USER_TIMER_PERIOD;
  }
}

boolean isMyAddress() {
  uint8_t addr[4] = {iqrf.RxBuf[2], iqrf.RxBuf[3], iqrf.RxBuf[4], iqrf.RxBuf[5]};
  return addr == my_addr ? true : false;
}

void receivePing() {
  if (isMyAddress()) {
    sendPong();
  }
}

void sendPong() {
  uint8_t packet[6] = {0, 1, my_addr[0], my_addr[1], my_addr[2], my_addr[3]};
  if (iqrf.appTimerAck) {
    iqrf.TxBuf = (uint8_t *)malloc(sizeof(packet));
    if (iqrf.TxBuf != NULL) {
      memcpy(iqrf.TxBuf, (uint8_t *)&packet, sizeof(packet));
      iqrf.testPktId = IQRF_SendData(iqrf.TxBuf, sizeof(packet), 1);
    }
    iqrf.appTimerAck = 0;
  }
}

void setColor() {
  uint8_t red_value = iqrf.RxBuf[6];
  uint8_t green_value = iqrf.RxBuf[7];
  uint8_t blue_value = iqrf.RxBuf[8];
  uint8_t alpha_value = iqrf.RxBuf[9];
  if (isMyAddress() && alpha_value == 0x00) {
    analogWrite(red_led, red_value);
    analogWrite(green_led, green_value);
    analogWrite(blue_led, blue_value);
  }
}

void AppTimerHandler() {
  iqrf.appTimerAck = 1;
}


void IqrfRx() {
  IQRF_GetRxData(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.print("IQRF receive done: ");
  Serial.write(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.println();
  uint8_t prot_version = iqrf.RxBuf[0];
  if (prot_version == 0x00) {
    uint8_t prot_type = iqrf.RxBuf[1];
    if (prot_type == 0x00) {
      receivePing();
    } else if (prot_type == 0x02) {
      setColor();
    }
  }
}

void IqrfTx(uint8_t txPktId, uint8_t txPktResult) {
  Serial.println("IQRF send done");
}

