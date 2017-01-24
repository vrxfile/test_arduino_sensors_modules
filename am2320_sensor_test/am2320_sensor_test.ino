/*
  Пример работы с датчиком температуры/влажности AM2320
  Created by Rostislav Varzar
*/

#include <AM2320.h>

AM2320 sensor;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  sensor.begin();
}

void loop() {
  // Измерение
  if (sensor.measure())
  {
    float t = sensor.getTemperature();
    float h = sensor.getHumidity();
    // Вывод измеренных значений
    Serial.println("Temperature: " + String(t, 1) + " *C");
    Serial.println("Humidity: " + String(h, 1) + " %");
  }
  delay(2500);
}
