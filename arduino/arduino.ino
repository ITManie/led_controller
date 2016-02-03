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


/**
 * Local prototypes
 */
void MyIqrfRxHandler();
void MyIqrfTxHandler(UINT8 txPktId, UINT8 txPktResult);
void AppTimerHandler();
void cb_timer1ms();


/**
 * Global variables
 */

// App data
typedef struct 
{
  uint8_t myIqrfRxBuf[IQ_PKT_SIZE];
  uint8_t *myIqrfTxBuf;
  uint8_t testPktId;
  volatile uint16_t appTimer;
  volatile uint8_t appTimerAck;
} app_vars_t;

app_vars_t app_vars;

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
  IQRF_Init(MyIqrfRxHandler, MyIqrfTxHandler);
  MsTimer2::set(1, cb_timer1ms);
  MsTimer2::start();
  memset(&app_vars, 0, sizeof(app_vars_t));
  app_vars.appTimer = USER_TIMER_PERIOD;
  Serial.println("Init done.");
}

/**
 * Main
 */

void loop() {
  IQRF_Driver();
}

void cb_timer1ms(void) {
  if (app_vars.appTimer) {              
    if ((--app_vars.appTimer) == 0) {
      AppTimerHandler();
      app_vars.appTimer = USER_TIMER_PERIOD;
    }
  }
}

void AppTimerHandler(void) {
  app_vars.appTimerAck = TRUE;
}


void MyIqrfRxHandler(void) {
  IQRF_GetRxData(app_vars.myIqrfRxBuf, IQRF_GetRxDataSize());
  Serial.print("IQRF receive done: ");
  Serial.write(app_vars.myIqrfRxBuf, IQRF_GetRxDataSize());
  Serial.println();
}

void MyIqrfTxHandler(UINT8 txPktId, UINT8 txPktResult) {
  Serial.println("IQRF send done");
}

