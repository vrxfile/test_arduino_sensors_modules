/*
  Пример работы с модулем RGB светодиода
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include "TLC59108.h"

#define HW_RESET_PIN 0 // Только програмнный сброс
#define I2C_ADDR TLC59108::I2C_ADDR::BASE

TLC59108 leds(I2C_ADDR + 7); // Без перемычек добавляется 3 бита адреса

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация модуля
  Wire.begin();
  leds.init(HW_RESET_PIN);
  leds.setLedOutputMode(TLC59108::LED_MODE::PWM_IND);
}

void loop() {
  // Плавное загорание/гашение каждого светодиода
  for (byte channel = 0; channel < 7; channel++)
  {
    for (byte pwm = 0; pwm < 0xff; pwm++) {
      leds.setBrightness(channel, pwm);
      delay(10);
    }
    for (byte pwm = 0xfe; pwm < 0xff; pwm--) {
      leds.setBrightness(channel, pwm);
      delay(10);
    }
  }
  // Плавное загорание/гашение каждого всех светодиодов
  for (byte pwm = 0; pwm < 0xff; pwm++) {
    leds.setAllBrightness(pwm);
    delay(10);
  }
  for (byte pwm = 0xfe; pwm < 0xff; pwm--) {
    leds.setAllBrightness(pwm);
    delay(10);
  }
}



