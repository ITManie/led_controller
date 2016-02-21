/*
                       +-----+
          +------------| USB |------------+
          |            +-----+            |
 IQRF_SCK | [*]D13                 D12[*] | IQRF_MISO
          | [ ]3.3V                D11[*]~| IQRF_MOSI
          | [ ]V.ref     ___       D10[*]~| IQRF_SS
          | [ ]A0       / N \       D9[ ]~|
          | [ ]A1      /  A  \      D8[ ] |
          | [ ]A2      \  N  /      D7[ ] |
          | [ ]A3       \_0_/       D6[*]~| LED_RED
          | [ ]A4                   D5[*]~| LED_GREEN
          | [ ]A5                   D4[ ] |
          | [ ]A6                   D3[*]~| LED_BLUE
          | [ ]A7                   D2[ ] |
 IQRF_+5V | [*]5V                  GND[*] | LED_GND
          | [ ]RST                 RST[ ] |
 IQRF_GND | [*]GND   5V MOSI GND   TX1[ ] |
          | [ ]Vin   [ ] [ ] [ ]   RX1[ ] |
          |          [ ] [ ] [ ]          |
          |          MISO SCK RST         |
          | NANO-V3                       |
          +-------------------------------+
       http://busyducks.com/ascii-art-arduinos
 */
#include <SPI.h>
#include <MsTimer2.h>
#include <iqrf_library.h>

#define USER_TIMER_PERIOD 5000 // 5 sec

void IqrfRx();
void IqrfTx(uint8_t txPktId, uint8_t txPktResult);
void cb_timer1ms();

// Set adress to 00.00.00.00
uint8_t my_addr[4] = {0x00, 0x00, 0x00, 0x00};
// Set version of protocol
uint8_t ver = 0x00;

/**
 * Data structure
 */
typedef struct 
{
  uint8_t RxBuf[IQ_PKT_SIZE];
  uint8_t *TxBuf;
  uint8_t testPktId;
  volatile uint16_t appTimer;
  volatile uint8_t appTimerAck;
} iqrf_t;

iqrf_t iqrf;

/**
 * Define pins of RGB LED
 */
const int red_led = 6;
const int green_led = 5;
const int blue_led = 3;

/**
 * Init peripherals
 * @param none
 * @return none
 */

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  IQRF_Init(IqrfRx, IqrfTx);
  Serial.println("IQRF module: " + IQRF_GetModuleType());
  MsTimer2::set(1, cb_timer1ms);
  MsTimer2::start();
  memset(&iqrf, 0, sizeof(iqrf_t));
  iqrf.appTimer = USER_TIMER_PERIOD;
  Serial.println("Init done.");
}

/**
 * Main loop
 * @param none
 * @return none
 */

void loop() {
  IQRF_Driver();
}
