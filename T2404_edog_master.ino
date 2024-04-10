#include <Wire.h>
#include <stdlib.h>
#include "main.h"
#include "edog.h"
#include "PicoCombo2403.h"

uint32_t next_power_off_ms;
uint32_t next_watchdog_reset_ms;
uint32_t next_off_1_ms;
bool     off_1 = false;


void setup() {
  Serial1.setTX(PIN_UART0_TX);
  Serial1.setRX(PIN_UART0_RX);
  Serial2.setTX(PIN_UART1_TX);
  Serial2.setRX(PIN_UART1_RX);

  Wire1.setSDA(PIN_I2C1_SDA);
  Wire1.setSCL(PIN_I2C1_SCL);

  Wire1.begin();
  Wire1.setClock(100000);


  Serial.begin(9600);
  Serial1.begin(115200);
  Serial2.begin(9600);

  delay(3000);
  Serial.println(APP_NAME);
  Serial.println(__DATE__); Serial.println(__TIME__);
  
  edog_initialize();
  edog_build_test_data();
  edog_test_eeprom_write_read();
  delay(5);
  edog_set_wd_timeout(4000);
  delay(1);
  edog_set_sleep_time(10000);
  delay(10);

next_power_off_ms = millis() + 4000;
next_watchdog_reset_ms  = millis() + 5000;
next_off_1_ms = millis() + 60;

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial1.print(0xAA);
  if (millis() > next_watchdog_reset_ms)
  {
    //edog_clear_watchdog();
    next_watchdog_reset_ms  = millis() + 5000;
  }
  if (millis() > next_power_off_ms)
  {
    edog_switch_off();
    next_power_off_ms = millis() + 30000;

    //edog_read_eeprom(0x0180);
  }

  if (millis() > next_off_1_ms)
  {
      if (off_1) edog_switch_off_1(0);
      else  edog_switch_off_1(1);
      off_1 = !off_1;
      next_off_1_ms = millis() + 100;
  }

}
