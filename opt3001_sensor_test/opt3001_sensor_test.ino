/*
  Пример работы с модулем цифрового датчика освещенности OPT3001
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include <ClosedCube_OPT3001.h>

ClosedCube_OPT3001 opt3001;
#define OPT3001_ADDRESS 0x44

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  opt3001.begin(OPT3001_ADDRESS);
}

void loop() {
  // Измерение
  OPT3001 result = opt3001.readResult();
  float l = result.lux;
  // Вывод измеренных значений в терминал
  Serial.println("Ambient light intensity: " + String(l, 1) + " lx");
  delay(250);
}
