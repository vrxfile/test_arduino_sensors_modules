/*
  Пример работы с датчиком пыли GP2Y1010AUF
  Created by Rostislav Varzar
*/

#include <SharpDust.h>

#define DUST_LED_PIN 13
#define DUST_MEASURE_PIN A2

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  SharpDust.begin(DUST_LED_PIN, DUST_MEASURE_PIN);
}

void loop() {
  // Измерение
  float c = SharpDust.measure();
  // Вывод измеренных значений
  Serial.println("Dust concentration: " + String(c, 2) + " mg/m^3");
  delay(250);
}
