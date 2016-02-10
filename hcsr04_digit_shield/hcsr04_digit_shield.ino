/*
  Пример работы с УЗ датчиком расстояния HC-SR04
  Created by Rostislav Varzar
*/
#include <DigitShield.h>

#define trigPin 10
#define echoPin 11
int maximumRange = 200;
int minimumRange = 0;
long duration = 0;
float distance = 0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выводов для работы с УЗ датчиком
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Инициализация цифрового дисплея
  DigitShield.begin();
  DigitShield.setPrecision(1);
}

void loop() {
  // Измерение
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  if (distance >= maximumRange || distance <= minimumRange) {
    distance = -1;
  }
  // Вывод измеренных значений на цифровой дисплей
  DigitShield.setValue(distance);
  delay(250);
}
