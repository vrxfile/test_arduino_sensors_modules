/*
  Пример работы с датчиками атмосферного давления BMP085/BMP180
  Created by Rostislav Varzar
*/
#include <Adafruit_BMP085_U.h>

Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);

float p, h, t;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика BMP085/BMP180
  if (!bmp.begin())
  {
    Serial.println("Could not find a valid BMP085 sensor!");
  }
  delay(1000);
}

void loop() {
  // Измерение давления, высоты и температуры
  sensors_event_t p_event;
  bmp.getEvent(&p_event);
  if (p_event.pressure)
  {
    p = p_event.pressure * 7.5006 / 10;
    bmp.getTemperature(&t);
    float seaLevelPressure = SENSORS_PRESSURE_SEALEVELHPA;
    h = bmp.pressureToAltitude(seaLevelPressure, p_event.pressure);
  }
  // Вывод измеренных значений
  Serial.print(String(p, 1));
  Serial.print("\t");
  Serial.print(String(h, 1));
  Serial.print("\t");
  Serial.print(String(t, 1));
  Serial.print("\t");

  Serial.println();

  delay(100);
}
