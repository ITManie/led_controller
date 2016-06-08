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

/*
                      _____
           __________| USB |__________
          |          |_____|          |
 IQRF_SCK | [*]D13             D12[*] | IQRF_MISO
          | [ ]3.3V            D11[*]~| IQRF_MOSI
          | [ ]V.ref   ___     D10[*]~| IQRF_SS
          | [ ]A0     | N |     D9[*]~| IQRF_TRPWR
          | [ ]A1     | A |     D8[ ] |
          | [ ]A2     | N |     D7[ ] |
          | [ ]A3     |_0_|     D6[*]~| LED_BLUE
          | [ ]A4               D5[*]~| LED_RED
          | [ ]A5               D4[ ] |
          | [ ]A6               D3[*]~| LED_GREEN
          | [ ]A7               D2[ ] |
 IQRF_+5V | [*]5V              GND[*] | LED_GND
          | [ ]RST             RST[ ] |
 IQRF_GND | [*]GND 5V MOSI GND TX1[ ] |
          | [ ]Vin [ ] [ ] [ ] RX1[ ] |
          |        [ ] [ ] [ ]        |
          |       MISO SCK RST        |
          | NANO-V3                   |
          |___________________________|
 */
#include <Arduino.h>
#include <SPI.h>
#include <MsTimer2.h>
#include <iqrf_library.h>

#define DEBUG // Debug mode
#define USER_TIMER_PERIOD 2000 // 2 sec

void msTimerCallback();
boolean isMyAddress(uint8_t buf[]);
void receivePing();
void sendPong(uint8_t addr[], uint8_t buf[]);
void setColor(uint8_t buf[]);
void setColorRGB(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
void rxHandler();
void txHandler(uint8_t packetId, uint8_t packetResult);

// Set adress to 00.00.00.00
uint8_t my_addr[4] = {0x00, 0x00, 0x00, 0x00};
// Set protocol version
uint8_t ver = 0x00;

/**
 * Data structure
 */
typedef struct {
  uint8_t rxBuffer[IQ_PKT_SIZE];
  uint8_t *txBuffer;
  uint8_t packetId;
  volatile uint16_t timer;
  volatile bool timerAck;
} iqrf_t;
iqrf_t iqrf;

/**
 * Define pins of RGB LED
 */
const int red_led = 5;
const int green_led = 3;
const int blue_led = 6;

/**
 * Init peripherals
 */
void setup() {
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
  Serial.begin(9600);
  IQRF_Init(rxHandler, txHandler);
  switch(IQRF_GetModuleType()) {
    case TR_52D:
      Serial.println("IQRF module: TR-52D");
      break;
    case TR_72D:
      Serial.println("IQRF module: TR-72D");
      break;
    default:
      Serial.println("IQRF module: UNKNOWN");
      break;
  }
  MsTimer2::set(1, msTimerCallback);
  MsTimer2::start();
  memset(&iqrf, 0, sizeof(iqrf_t));
  iqrf.timer = USER_TIMER_PERIOD;
  Serial.println("Init done.");
}

/**
 * Main loop
 */
void loop() {
  // TR module SPI comunication driver
  IQRF_Driver();
}
