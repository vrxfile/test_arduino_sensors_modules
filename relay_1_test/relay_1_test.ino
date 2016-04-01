/*
  Пример управления модулем одного реле (или MOS транзистора)
  Created by Rostislav Varzar
*/

#define RELAYPIN 12

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выхода реле
  pinMode(RELAYPIN, OUTPUT);
}

void loop() {
  // Включение
  digitalWrite(RELAYPIN, HIGH);
  // Пауза
  delay(1000);
  // Выключение
  digitalWrite(RELAYPIN, LOW);
  // Пауза
  delay(1000);
}
