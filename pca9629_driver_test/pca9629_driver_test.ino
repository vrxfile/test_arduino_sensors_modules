/*
  Пример работы с моторным драйвером PCA9629A
  Created by Rostislav Varzar
*/
#include <Wire.h>

#define driver_addr 0x20

uint8_t m_ctl = 0b00000000;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  init_driver();
  delay(500);
  motor1_backward(); delay(500);
  motor1_forward(); delay(500);
  motor1_stop(); delay(500);
  motor2_backward(); delay(500);
  motor2_forward(); delay(500);
  motor2_stop(); delay(500);
  motor1_backward(); motor2_backward(); delay(500);
  motor1_forward(); motor2_forward(); delay(500);
  motor1_stop(); motor2_stop(); delay(500);
}

void loop() {
}

// Инициализация драйвера
void init_driver() {
  Wire.begin();
  Wire.setClock(100000L);
  Wire.beginTransmission(driver_addr);
  Wire.write(0x00);       // Регистр режима работы
  Wire.write(0b00100000); // Выход прерывания и отклик от разных адресов отключены
  Wire.endTransmission();
  Wire.beginTransmission(driver_addr);
  Wire.write(0x03);       // Конфигурационный регистр
  Wire.write(0b00001111); // P0 - P3 настроены как входы
  Wire.endTransmission();
}

void motor1_backward()
{
  m_ctl = m_ctl & 0b11111100;
  m_ctl = m_ctl | 0b00000001;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor1_forward()
{
  m_ctl = m_ctl & 0b11111100;
  m_ctl = m_ctl | 0b00000010;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor1_stop()
{
  m_ctl = m_ctl & 0b11111100;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor2_backward()
{
  m_ctl = m_ctl & 0b11110011;
  m_ctl = m_ctl | 0b00000100;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor2_forward()
{
  m_ctl = m_ctl & 0b11110011;
  m_ctl = m_ctl | 0b00001000;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor2_stop()
{
  m_ctl = m_ctl & 0b11110011;
  Wire.beginTransmission(driver_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}
