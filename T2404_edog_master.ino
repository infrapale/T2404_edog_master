#include <Wire.h>
#include <stdlib.h>
#include "main.h"
#include "edog.h"
#include "PicoCombo2403.h"

uint32_t next_power_off_ms;
uint32_t next_watchdog_reset_ms;


void setup() {
  Serial1.setTX(PIN_UART0_TX);
  Serial1.setRX(PIN_UART0_RX);
  Serial2.setTX(PIN_UART1_TX);
  Serial2.setRX(PIN_UART1_RX);

  Wire.begin();
  Wire.setClock(100000);


  Serial.begin(9600);
  Serial1.begin(115200);
  Serial2.begin(9600);

  delay(3000);
  Serial.println(APP_NAME);
  Serial.println(__DATE__); Serial.println(__TIME__);
  
  edog_initialize();
  edog_set_wd_timeout(1000);
  delay(1);
  edog_set_sleep_time(1000);
  delay(10);

next_power_off_ms = millis() + 1000;
next_watchdog_reset_ms  = millis() + 500;

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial1.print(0xAA);
}
