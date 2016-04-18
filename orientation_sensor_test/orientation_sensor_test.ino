/*
  Пример работы с датчиком ускорения ADXL345
  Created by Rostislav Varzar
*/
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(10345);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика
  if (!accel.begin())
  {
    Serial.println("Could not find a valid ADXL345 sensor!");
  }
  else
  {
    accel.setRange(ADXL345_RANGE_16_G);
    accel.setDataRate(ADXL345_DATARATE_200_HZ);
  }
  delay(1000);
}

void loop() {
  // Измерение
  sensors_event_t a_event;
  accel.getEvent(&a_event);
  float ax = a_event.acceleration.x;
  float ay = a_event.acceleration.y;
  float az = a_event.acceleration.z;
  // Вывод измеренных значений
  Serial.print("ADXL345: ");
  Serial.print("X = " + String(ax, 1) + " ");
  Serial.print("Y = " + String(ay, 1) + " ");
  Serial.println("Z = " + String(az, 1));
  delay(100);
}
