/*
  Пример управления пьезоэлектрическим динамиком
  Created by Rostislav Varzar
*/

#define BUZZERPIN 3

void setup() {
  // Инициализация выхода динамика
  pinMode(BUZZERPIN, OUTPUT);
}

void loop() {
  // Включение
  tone(BUZZERPIN, 440, 200);
  // Пауза
  delay(1000);
  // Выключение
  noTone(BUZZERPIN);
  // Пауза
  delay(1000);
}
