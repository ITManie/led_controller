/**
 * Copyright (C) 2016 Roman Ondráček
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
  #ifdef DEBUG
  Serial.println("Receive ping.");
  #endif
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
    // Alocate memory for Tx packet
    buf = (uint8_t *)malloc(sizeof(packet));
    if (buf != NULL) {
      // Copy data from packet to IQRF Tx packet
      memcpy(buf, (uint8_t *)&packet, sizeof(packet));
      // Dend data and unalocate data buffer
      iqrf.testPktId = IQRF_SendData(buf, sizeof(packet), 1);
      #ifdef DEBUG
      Serial.println("Sending pong.");
      #endif
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
  #ifdef DEBUG
  Serial.println("RED\tGREEN\tBLUE\tALPHA");
  Serial.print(red_value, HEX); Serial.print("\t");
  Serial.print(green_value, HEX); Serial.print("\t");
  Serial.print(blue_value, HEX); Serial.print("\t");
  Serial.println(alpha_value, HEX);
  #endif
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
  #ifdef DEBUG
  Serial.print("IQRF receive done: ");
  Serial.write(iqrf.RxBuf, IQRF_GetRxDataSize());
  Serial.println();
  #endif
  uint8_t prot_version = iqrf.RxBuf[0];
  #ifdef DEBUG
  Serial.print("Protocol version: ");
  Serial.println(prot_version, HEX);
  #endif
  if (prot_version == 0x00) {
    uint8_t prot_type = iqrf.RxBuf[1];
    #ifdef DEBUG
    Serial.print("Protocol type: ");
    Serial.println(prot_type, HEX);
    #endif
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
  #ifdef DEBUG
  Serial.println("IQRF send done");
  #endif
}

