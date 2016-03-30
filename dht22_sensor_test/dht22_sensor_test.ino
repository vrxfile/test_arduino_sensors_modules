/*
  Пример работы с датчиком температуры/влажности DHT22
  Created by Rostislav Varzar
*/

#include <DHT.h>

#define DHTPIN 12
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  dht.begin();
}

void loop() {
  // Измерение
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Вывод измеренных значений
  Serial.println("Temperature: " + String(t, 1) + " *C");
  Serial.println("Humidity: " + String(h, 1) + " %");
  delay(2500);
}
