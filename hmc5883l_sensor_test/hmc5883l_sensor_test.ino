/*
  Пример работы с модулем цифрового компаса HCM5883L
  Created by Rostislav Varzar
*/
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(15883);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика HMC5883L
  if (!mag.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor!");
  }
  delay(1000);
}

void loop() {
  // Измерение магнитного поля
  sensors_event_t m_event;
  mag.getEvent(&m_event);
  float mx = m_event.magnetic.x;
  float my = m_event.magnetic.y;
  float mz = m_event.magnetic.z;
  // Вывод измеренных значений
  Serial.println("MX = " + String(mx, 1) + " uT");
  Serial.println("MY = " + String(my, 1) + " uT");
  Serial.println("MZ = " + String(mz, 1) + " uT");
  Serial.println();
  delay(250);
}
