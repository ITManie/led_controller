/*
                      +-----+
         +------------| USB |------------+
         |            +-----+            |
    SCK  | [*]D13                 D12[*] |  MISO
         | [ ]3.3V                D11[*]~|  MOSI
         | [ ]V.ref     ___       D10[*]~|  SS
         | [ ]A0       / N \       D9[ ]~|
         | [ ]A1      /  A  \      D8[ ] |
         | [ ]A2      \  N  /      D7[ ] |
         | [ ]A3       \_0_/       D6[*]~|  RED_LED
         | [ ]A4                   D5[*]~|  GREEN_LED
         | [ ]A5                   D4[ ] |
         | [ ]A6                   D3[*]~|  BLUE_LED
         | [ ]A7                   D2[ ] |
         | [ ]5V                  GND[ ] |     
         | [ ]RST                 RST[ ] |
         | [ ]GND   5V MOSI GND   TX1[ ] |
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

// Set adress to 00.00.00.00
uint8_t my_address[4] = {0x00, 0x00, 0x00, 0x00};
// Set version of protocol
uint8_t ver = 0x00;

/**
 * Global variables
 */

// App data
typedef struct 
{
  uint8_t RxBuf[IQ_PKT_SIZE];
  uint8_t *TxBuf;
  uint8_t testPktId;
  volatile uint16_t appTimer;
  volatile uint8_t appTimerAck;
} iqrf_t;

iqrf_t iqrf;

// Const data
const int red_led = 6;
const int green_led = 5;
const int blue_led = 3;

/**
 * Init peripherals
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
 * Main
 */

void loop() {
  IQRF_Driver();
}
