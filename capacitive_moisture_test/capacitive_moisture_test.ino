/*
  Пример работы с датчиком влажности почвы ёмкостным
  Created by Rostislav Varzar
*/

#define SENSPIN A0
const float air_value = 545.0;
const float water_value = 292.0;
const float moisture_0 = 0.0;
const float moisture_100 = 100.0;


void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входа аналогового датчика
  pinMode(SENSPIN, INPUT);
}

void loop() {
  // Измерение
  float sensor_data = analogRead(SENSPIN);
  float moisture = map(sensor_data, air_value, water_value, moisture_0, moisture_100);
  // Вывод измеренных значений
  Serial.println("Moisture sensor: " + String(moisture) + " %");
  delay(100);
}
