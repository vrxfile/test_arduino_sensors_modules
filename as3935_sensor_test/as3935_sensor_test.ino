/*
  Пример работы с модулем датчика грозовых разрядов AS3935
  Created by Rostislav Varzar
*/
#include <Wire.h>

#define sensor_addr 0x03 // Without jumpers

float energy_data = 0;
float dist_data   = 0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  init_sensor();
  delay(500);
}

void loop() {
  // Измерение
  poll_sensor();
  // Вывод измеренных значений в терминал
  Serial.println("ENERGY   = " + String(energy_data, 1));
  Serial.println("DISTANCE = " + String(dist_data, 1));
  delay(350);
}

// Инициализация датчика
void init_sensor() {
  Wire.begin();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x00);       // Регистр управления усилителем и спящим режимом
  Wire.write(0b00100100); // Активный режим, AFE = 0b10010
  Wire.endTransmission();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x01);       // Регистр шумоподавления и watchdog
  Wire.write(0b00100010); // NFL = 0b010, WD = 0b0010
  Wire.endTransmission();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x02);       // Регистр настройки распознавания сигнала
  Wire.write(0b11000010); // Минимальное количество импульсов = 0, уменьшение чувсвтительности к искрам 0b0010
  Wire.endTransmission();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x03);       // Регистр настройки антенны
  Wire.write(0b00000000); // По умолчанию всё "0"
  Wire.endTransmission();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x08);       // Регистр настройки конденсатора колебательного контура
  Wire.write(0b00000000); // По умолчанию всё "0"
  Wire.endTransmission();
  // Или установка всего по умолчанию
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x3C);
  Wire.write(0x96);
  Wire.endTransmission();
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x3D);
  Wire.write(0x96);
  Wire.endTransmission();
}

// Получение данных с датчика
void poll_sensor() {
  unsigned int sensor_data[4];
  Wire.beginTransmission(sensor_addr);
  Wire.write(0x04); // Регистр данных
  Wire.endTransmission();
  Wire.requestFrom(sensor_addr, 4);
  if (Wire.available() == 4) {
    sensor_data[0] = Wire.read();
    sensor_data[1] = Wire.read();
    sensor_data[2] = Wire.read();
    sensor_data[3] = Wire.read();
  }
  energy_data = (float)sensor_data[2] * 65536.0 + (float)sensor_data[1] * 256.0 + (float)sensor_data[0];
  dist_data = (float)sensor_data[3];
}

