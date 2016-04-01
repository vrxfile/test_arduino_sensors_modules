/*
  Пример работы с ИК датчиком движения HC-SR501
  Created by Rostislav Varzar
*/

#define SENSPIN 12

int sensor_data = 0;
int old_sensor_data = 0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входа цифрового датчика
  pinMode(SENSPIN, INPUT);
}

void loop() {
  // Измерение
  sensor_data = digitalRead(SENSPIN);
  if (sensor_data != old_sensor_data)
  {
    Serial.println("Motion detected!");
  }
  old_sensor_data = sensor_data;
  delay(10);
}
