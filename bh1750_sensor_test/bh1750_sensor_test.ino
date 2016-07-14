/*
  Пример работы с модулем цифрового датчика освещенности BH1750
  Created by Rostislav Varzar
*/
#include <BH1750FVI.h>

BH1750FVI LightSensor_1;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  LightSensor_1.begin();
  LightSensor_1.setMode(Continuously_High_Resolution_Mode);
}

void loop() {
  // Измерение
  float l = LightSensor_1.getAmbientLight();
  // Вывод измеренных значений
  Serial.println("Ambient light intensity: " + String(l, 1) + " lx");
  delay(250);
}
