/*
  Пример работы с ИК датчиком препятствий E18-D80NK
  Created by Rostislav Varzar
*/

#define SENSPIN A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входа цифрового датчика
  pinMode(SENSPIN, INPUT_PULLUP);
}

void loop() {
  // Измерение
  int sensor_data = digitalRead(SENSPIN);
  // Вывод измеренных значений
  Serial.println("Digital IR sensor: " + String(sensor_data));
  delay(100);
}
