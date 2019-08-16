/*
  Пример работы с несколькими модулями цифрового лазерного датчика расстояния VL53L0X через I2C шилд
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include <VL53L0X.h>

VL53L0X lox1;
VL53L0X lox2;
VL53L0X lox3;
VL53L0X lox4;
VL53L0X lox5;

// Константы для I2C шилда
#define I2C_HUB_ADDR        0x70
#define EN_MASK             0x08
#define DEF_CHANNEL         0x00
#define MAX_CHANNEL         0x08

// I2C порт 0x07 - выводы D4 (SDA), D5 (SCL)
// I2C порт 0x06 - выводы D6 (SDA), D7 (SCL)
// I2C порт 0x05 - выводы D8 (SDA), D9 (SCL)
// I2C порт 0x04 - выводы D10 (SDA), D11 (SCL)
// I2C порт 0x03 - выводы D12 (SDA), D13 (SCL)

// Режим работы датчика
#define LONG_RANGE
//#define HIGH_SPEED
//#define HIGH_ACCURACY

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);

  // Инициализация I2C
  Wire.begin();

  // Инициализация датчика #1
  setBusChannel(0x07);
  lox1.init();
  lox1.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  lox1.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  lox1.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox1.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif
#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  lox1.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  lox1.setMeasurementTimingBudget(200000);
#endif

  // Инициализация датчика #2
  setBusChannel(0x06);
  lox2.init();
  lox2.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  lox2.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  lox2.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox2.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif
#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  lox2.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  lox2.setMeasurementTimingBudget(200000);
#endif

  // Инициализация датчика #3
  setBusChannel(0x05);
  lox3.init();
  lox3.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  lox3.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  lox3.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox3.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif
#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  lox3.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  lox3.setMeasurementTimingBudget(200000);
#endif

  // Инициализация датчика #4
  setBusChannel(0x04);
  lox4.init();
  lox4.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  lox4.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  lox4.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox4.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif
#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  lox4.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  lox4.setMeasurementTimingBudget(200000);
#endif

  // Инициализация датчика #5
  setBusChannel(0x03);
  lox5.init();
  lox5.setTimeout(500);
#if defined LONG_RANGE
  // lower the return signal rate limit (default is 0.25 MCPS)
  lox5.setSignalRateLimit(0.1);
  // increase laser pulse periods (defaults are 14 and 10 PCLKs)
  lox5.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
  lox5.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
#endif
#if defined HIGH_SPEED
  // reduce timing budget to 20 ms (default is about 33 ms)
  lox5.setMeasurementTimingBudget(20000);
#elif defined HIGH_ACCURACY
  // increase timing budget to 200 ms
  lox5.setMeasurementTimingBudget(200000);
#endif
}

void loop() {
  // Считывание датчика #1
  setBusChannel(0x07);
  float dist1 = lox1.readRangeSingleMillimeters();

  // Считывание датчика #2
  setBusChannel(0x06);
  float dist2 = lox2.readRangeSingleMillimeters();

  // Считывание датчика #3
  setBusChannel(0x05);
  float dist3 = lox3.readRangeSingleMillimeters();

  // Считывание датчика #4
  setBusChannel(0x04);
  float dist4 = lox4.readRangeSingleMillimeters();

  // Считывание датчика #5
  setBusChannel(0x03);
  float dist5 = lox5.readRangeSingleMillimeters();

  // Вывод измеренных значений в терминал
  Serial.print(String(dist1, 0));
  Serial.print(" ");
  Serial.print(String(dist2, 0));
  Serial.print(" ");
  Serial.print(String(dist3, 0));
  Serial.print(" ");
  Serial.print(String(dist4, 0));
  Serial.print(" ");
  Serial.println(String(dist5, 0));
  delay(250);
}

// Функция установки нужного выхода I2C
bool setBusChannel(uint8_t i2c_channel)
{
  if (i2c_channel >= MAX_CHANNEL)
  {
    return false;
  }
  else
  {
    Wire.beginTransmission(I2C_HUB_ADDR);
    Wire.write(i2c_channel | EN_MASK);
    Wire.endTransmission();
    return true;
  }
}
