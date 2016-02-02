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

//App data
typedef struct 
{
  uint8_t myIqrfRxBuf[IQ_PKT_SIZE];
  uint8_t *myIqrfTxBuf;
  uint8_t testPktId;
  volatile uint16_t appTimer;
  volatile uint8_t appTimerAck;
} app_vars_t;

app_vars_t app_vars;

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

