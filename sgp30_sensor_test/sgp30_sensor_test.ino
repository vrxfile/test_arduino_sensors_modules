/*
  Пример работы с модулем цифрового датчика концентрации летучих органических соединений SGP30
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp30;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  if (!sgp30.begin())
    Serial.println("Sensor SGP30 not found!");
}

void loop() {
  float eco2 = 0;
  float tvoc = 0;
  if (!sgp30.IAQmeasure())
  {
    Serial.println("Measurement failed!");
    return;
  }
  tvoc = sgp30.TVOC;
  eco2 = sgp30.eCO2;
  Serial.println("TVOC = " + String(tvoc, 1) + " ppb");
  Serial.println("eCO2 = " + String(eco2, 1) + " ppm");
  delay(1000);
}
