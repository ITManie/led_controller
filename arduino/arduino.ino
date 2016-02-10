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
  Serial.println("IQRF module: " + IQRF_GetModuleType());
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
  uint8_t prot_version = app_vars.myIqrfRxBuf[0];
  Serial.println("Protocol version: " + prot_version);
  if (prot_version == 0x00) {
    uint8_t prot_type = app_vars.myIqrfRxBuf[1];
    Serial.println("Protocol type: " + prot_type);
    if (prot_type == 0x01) {
      uint8_t address[4] = {app_vars.myIqrfRxBuf[2], app_vars.myIqrfRxBuf[3], app_vars.myIqrfRxBuf[4], app_vars.myIqrfRxBuf[5]};
      Serial.print("Address: " + address[0]);
      Serial.print(address[1] + ".");
      Serial.print(address[2] + ".");
      Serial.println(address[3]);
      if (address == my_address) {
        uint8_t red_value = app_vars.myIqrfRxBuf[6];
        Serial.println("Red: " + red_value);
        uint8_t green_value = app_vars.myIqrfRxBuf[7];
        Serial.println("Green: " + green_value);
        uint8_t blue_value = app_vars.myIqrfRxBuf[8];
        Serial.println("Blue: " + blue_value);
        uint8_t alpha_value = app_vars.myIqrfRxBuf[9];
        Serial.println("Aplha:" + alpha_value);
        if (alpha_value == 0x00) {
          analogWrite(red_led, red_value);
          analogWrite(green_led, green_value);
          analogWrite(blue_led, blue_value);
        }
      }
    }
  }
}

void MyIqrfTxHandler(UINT8 txPktId, UINT8 txPktResult) {
  Serial.println("IQRF send done");
}

