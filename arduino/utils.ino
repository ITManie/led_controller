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
 * 1ms timer callback
 */
void msTimerCallback() {
  // App timer, call handler
  if (appVars.timer && (--appVars.timer) == 0) {
    appVars.timerAck = true;
    appVars.timer = USER_TIMER_PERIOD;
  }
}

/**
 * Check address from packet and address of controller
 * @param buf[] IQRF Rx buffer
 * @return boolean
 */
boolean isMyAddress(uint8_t buf[] = appVars.rxBuffer) {
  if (buf[2] == my_addr[0] && buf[3] == my_addr[1] && buf[4] == my_addr[2] && buf[5] == my_addr[3]) {
    return true;
  }
  return false;
}

/**
 * Recieve ping packet and call function sendPong
 */
void receivePing() {
  #ifdef DEBUG
  Serial.println("Receive ping.");
  #endif
  sendPong(my_addr, appVars.txBuffer);
}

/**
 * Send pong packet (answer on the ping packet)
 * @param addr[] Address of this controller (defined in my_addr)
 * @param buf[] IQRF Tx buffer
 */
void sendPong(uint8_t addr[], uint8_t buf[]) {
  uint8_t packet[6] = {0, 1, addr[0], addr[1], addr[2], addr[3]};
  if (appVars.timerAck) {
    // Alocate memory for Tx packet
    buf = (uint8_t *)malloc(sizeof(packet));
    if (buf != NULL) {
      // Copy data from packet to IQRF Tx packet
      memcpy(buf, (uint8_t *)&packet, sizeof(packet));
      // Dend data and unalocate data buffer
      appVars.packetId = iqrf.sendData(buf, sizeof(packet), 1);
      #ifdef DEBUG
      Serial.println("Sending pong.");
      #endif
    }
    appVars.timerAck = false;
  }
}

/**
 * Get data from set color packet and set color of RGB lED
 * @param buf[] IQRF Rx buffer
 */
void setColor(uint8_t buf[] = appVars.rxBuffer) {
  uint8_t red_value = buf[6];
  uint8_t green_value = buf[7];
  uint8_t blue_value = buf[8];
  uint8_t alpha_value = buf[9];
  setColorRGB(red_value, green_value, blue_value, alpha_value);
}

/**
 * Set color of RGB LED strip via PWM
 * @param red Value of red color (0-255)
 * @param green Value of green color (0-255)
 * @param blue Value of blue color (0-255)
 * @param alpha Value of alpha (0 - ON, 1 - OFF)
 */
void setColorRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
  #ifdef DEBUG
  Serial.println("RED\tGREEN\tBLUE\tALPHA");
  Serial.print(red, HEX); Serial.print("\t");
  Serial.print(green, HEX); Serial.print("\t");
  Serial.print(blue, HEX); Serial.print("\t");
  Serial.println(alpha, HEX);
  #endif
  if (alpha == 0) {
    analogWrite(red_led, red);
    analogWrite(green_led, green);
    analogWrite(blue_led, blue);
  } else {
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  }
}

/**
 * IQRF Rx handler
 */
void rxHandler() {
  iqrf.getData(appVars.rxBuffer, iqrf.getDataLength());
  #ifdef DEBUG
  Serial.print("IQRF receive done: ");
  Serial.write(appVars.rxBuffer, iqrf.getDataLength());
  Serial.println();
  #endif
  if (isMyAddress()) {
    uint8_t prot_version = appVars.rxBuffer[0];
    #ifdef DEBUG
    Serial.print("Protocol version: ");
    Serial.println(prot_version, HEX);
    #endif
    if (prot_version == 0) {
      uint8_t prot_type = appVars.rxBuffer[1];
      #ifdef DEBUG
      Serial.print("Protocol type: ");
      Serial.println(prot_type, HEX);
      #endif
      switch (prot_type) {
        case 0:
          receivePing();
          break;
        case 2:
          setColor();
          break;
      }
    }
  }
}

/**
 * IQRF Tx gandler
 * @param packetId Packet ID
 * @param packetResult Packet result
 */
void txHandler(uint8_t packetId, uint8_t packetResult) {
  #ifdef DEBUG
  Serial.println("IQRF send done");
  #endif
}
