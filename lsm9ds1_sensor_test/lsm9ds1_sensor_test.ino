/*
  Пример работы с модулем цифрового акселерометра/гироскопа/магнетометра LSM9DS1
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include <SparkFunLSM9DS1.h>

LSM9DS1 imu;
#define LSM9DS1_M   0x1E
#define LSM9DS1_AG  0x6B

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  imu.settings.device.commInterface = IMU_MODE_I2C;
  imu.settings.device.mAddress = LSM9DS1_M;
  imu.settings.device.agAddress = LSM9DS1_AG;
  bool imu_status = imu.begin();
  if (!imu_status)
    Serial.println("Failed to communicate with LSM9DS1!");
}

void loop() {
  // Измерение
  if (imu.gyroAvailable())
    imu.readGyro();
  if (imu.accelAvailable())
    imu.readAccel();
  if (imu.magAvailable())
    imu.readMag();
  float acc_x = imu.calcAccel(imu.ax);
  float acc_y = imu.calcAccel(imu.ay);
  float acc_z = imu.calcAccel(imu.az);
  float gyr_x = imu.calcGyro(imu.gx);
  float gyr_y = imu.calcGyro(imu.gy);
  float gyr_z = imu.calcGyro(imu.gz);
  float mag_x = imu.calcMag(imu.mx);
  float mag_y = imu.calcMag(imu.my);
  float mag_z = imu.calcMag(imu.mz);
  // Вывод измеренных значений в терминал
  Serial.println("ACC = " + String(acc_x, 2) + " " + String(acc_y, 2) + " " + String(acc_z, 2) + " ");
  Serial.println("GYR = " + String(gyr_x, 2) + " " + String(gyr_y, 2) + " " + String(gyr_z, 2) + " ");
  Serial.println("MAG = " + String(mag_x, 2) + " " + String(mag_y, 2) + " " + String(mag_z, 2) + " ");
  delay(250);
}
