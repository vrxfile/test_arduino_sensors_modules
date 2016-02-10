/*
  Пример работы с датчиком линии аналоговым
  Created by Rostislav Varzar
*/

#define SENSPIN A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входа аналогового датчика
  pinMode(SENSPIN, INPUT);
}

void loop() {
  // Измерение
  int sensor_data = analogRead(SENSPIN);
  // Вывод измеренных значений
  Serial.println("Analog line sensor: " + String(sensor_data));
  delay(100);
}
