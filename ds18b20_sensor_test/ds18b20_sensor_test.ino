/*
  Пример работы с датчиком температуры DS18B20
  Created by Rostislav Varzar
*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 12
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds_sensors(&oneWire);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  ds_sensors.begin();
}

void loop() {
  // Измерение
  ds_sensors.requestTemperatures();
  float t = ds_sensors.getTempCByIndex(0);
  // Вывод измеренных значений
  Serial.println("Temperature: " + String(t, 1) + " *C");
  delay(1000);
}
