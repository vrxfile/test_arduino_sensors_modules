/*
  Пример работы с датчиком DHT11 и платой Digit Shield
  Created by Rostislav Varzar
*/

#include <DHT.h>
#include <DigitShield.h>

#define DHTPIN 10
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация цифрового дисплея
  DigitShield.begin();
  // Инициализация датчика
  dht.begin();
}

void loop() {
  // Измерение
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Вывод температуры
  DigitShield.setPrecision(1);
  DigitShield.setValue(t);
  delay(5000);
  // Вывод влажности
  DigitShield.setPrecision(0);
  DigitShield.setValue(h);
  delay(5000);
}
