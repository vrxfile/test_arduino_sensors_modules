/*
  Пример работы с аналоговым датчиком звука (рисование графика в терминале)
  Created by Rostislav Varzar
*/

#define SENSPIN A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация входа аналогового датчика
  pinMode(SENSPIN, INPUT);
}

void loop() {
  // Измерение
  int sensor_data = analogRead(SENSPIN);
  // Расчет количества "плюсиков"
  int num_symbols = sensor_data / 5 + 1;
  // Вывод плюсиков в терминал
  for (int i = 0; i < num_symbols; i ++)
  {
    Serial.print("+");
  }
  Serial.println();
  delay(1);
}
