/*
  Пример работы с 10-осевым датчиком положения в пространстве
  Created by Rostislav Varzar
*/
#include <L3G.h>
#include <Adafruit_BMP085_U.h>
#include <Adafruit_ADXL345_U.h>
#include <Adafruit_HMC5883_U.h>

L3G gyro;
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(15883);
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(10345);

float ax, ay, az, gx, gy, gz, mx, my, mz, p, h, t;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчика BMP085
  if (!bmp.begin())
  {
    Serial.println("Could not find a valid BMP085 sensor!");
  }
  // Инициализация датчика L3G4200D
  if (!gyro.init())
  {
    Serial.println("Failed to autodetect gyro type!");
  }
  else
  {
    gyro.enableDefault();
  }
  // Инициализация датчика HMC5883L
  if (!mag.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor!");
  }
  // Инициализация датчика ADXL345
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
  // Измерение ускорения
  sensors_event_t a_event;
  accel.getEvent(&a_event);
  ax = a_event.acceleration.x;
  ay = a_event.acceleration.y;
  az = a_event.acceleration.z;
  // Измерение углового ускорения
  gyro.read();
  gx = gyro.g.x / 1000;
  gy = gyro.g.y / 1000;
  gz = gyro.g.z / 1000;
  // Измерение магнитного поля
  sensors_event_t m_event;
  mag.getEvent(&m_event);
  mx = m_event.magnetic.x;
  my = m_event.magnetic.y;
  mz = m_event.magnetic.z;
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
  Serial.print(String(ax, 1));
  Serial.print("\t");
  Serial.print(String(ay, 1));
  Serial.print("\t");
  Serial.print(String(az, 1));
  Serial.print("\t");
  Serial.print(String(gx, 1));
  Serial.print("\t");
  Serial.print(String(gy, 1));
  Serial.print("\t");
  Serial.print(String(gz, 1));
  Serial.print("\t");
  Serial.print(String(mx, 1));
  Serial.print("\t");
  Serial.print(String(my, 1));
  Serial.print("\t");
  Serial.print(String(mz, 1));
  Serial.print("\t");
  Serial.print(String(p, 1));
  Serial.print("\t");
  Serial.print(String(h, 1));
  Serial.print("\t");
  Serial.print(String(t, 1));
  Serial.print("\t");

  Serial.println();

  delay(100);
}
