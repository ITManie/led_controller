void AppTimerHandler();
void cb_timer1ms();

void cb_timer1ms(void) {
  if (iqrf.appTimer && (--iqrf.appTimer) == 0) {
    AppTimerHandler();
    iqrf.appTimer = USER_TIMER_PERIOD;
  }
}

boolean isMyAddress(uint8_t my_addr[], uint8_t buf[]) {
  uint8_t addr[4] = {buf[2], buf[3], buf[4], buf[5]};
  if(addr == my_addr) {
    return true;
  } else {
    return false;
  }
}

void setColor(uint8_t buf[]) {
  uint8_t red_value = buf[6];
  uint8_t green_value = buf[7];
  uint8_t blue_value = buf[8];
  uint8_t alpha_value = buf[9];
  if (alpha_value == 0x00) {
    analogWrite(red_led, red_value);
    analogWrite(green_led, green_value);
    analogWrite(blue_led, blue_value);
  }
}

void AppTimerHandler(void) {
  iqrf.appTimerAck = TRUE;
}


void IqrfRx(void) {
  IQRF_GetRxData(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.print("IQRF receive done: ");
  Serial.write(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.println();
  uint8_t prot_version = iqrf.RxBuf[0];
  if (prot_version == 0x00) {
    uint8_t prot_type = iqrf.RxBuf[1];
    if (prot_type == 0x03) {
      if (isMyAddress(my_address, iqrf.RxBuf)) {
        setColor(iqrf.RxBuf);
      }
    }
  }
}

void IqrfTx(uint8_t txPktId, uint8_t txPktResult) {
  Serial.println("IQRF send done");
}

