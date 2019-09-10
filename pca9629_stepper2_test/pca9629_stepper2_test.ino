/*
  Пример работы с моторным драйвером PCA9629A
  Created by Rostislav Varzar
*/
#include <Wire.h>

#define driver_addr_1 0x20
#define driver_addr_2 0x23

void setup()
{
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  init_driver(driver_addr_1);
  delay(500);
  init_driver(driver_addr_2);
  delay(500);
}

void loop()
{
  // Вращение в одну сторону
  motor_forward(driver_addr_1, random(1000) + 1, random(64) + 32);
  motor_forward(driver_addr_2, random(1000) + 1, random(64) + 32);
  while (is_motor_running(driver_addr_1)) {
    delay(100); // Ожидание мотора
  }
  while (is_motor_running(driver_addr_2)) {
    delay(100); // Ожидание мотора
  }
  delay(500);
  // Вращение в другую сторону
  motor_backward(driver_addr_1, random(1000) + 1, random(64) + 32);
  motor_backward(driver_addr_2, random(1000) + 1, random(64) + 32);
  while (is_motor_running(driver_addr_1)) {
    delay(100); // Ожидание мотора
  }
  while (is_motor_running(driver_addr_2)) {
    delay(100); // Ожидание мотора
  }
  delay(500);
  // motor_stop(driver_addr_1); delay(500);
  // motor_stop(driver_addr_2); delay(500);
}

// Инициализация драйвера
void init_driver(uint8_t drv_addr)
{
  Wire.begin();
  Wire.setClock(100000L);
  Wire.beginTransmission(drv_addr);
  Wire.write(0x00);       // Регистр режима работы
  Wire.write(0b00100000); // Выход прерывания и отклик от разных адресов отключены
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x03);       // Конфигурационный регистр
  Wire.write(0b00001111); // P0 - P3 настроены как входы
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x0B);       // Регистр режима работы ШИМ
  Wire.write(0b01010000); // Двухфазный режим, OUT0-3 - моторные выходы
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x0C);       // Регистр состояния выходов
  Wire.write(0b00000000); // После остановки мотора - выходы переходят в лог. "1"
  Wire.endTransmission();
}

void motor_forward(uint8_t drv_addr, uint16_t n_steps, uint16_t m_speed)
{
  Wire.beginTransmission(drv_addr);
  Wire.write(0x16);       // Младший регистр ширины импульса управления мотором
  Wire.write(uint8_t(m_speed & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x17);       // Старший регистр ширины импульса управления мотором
  Wire.write(uint8_t((m_speed >> 8) & 0xFF | 0b10000000)); // Предделитель 0b100
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x12);       // Младший регистр количества шагов
  Wire.write(uint8_t(n_steps & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x13);       // Старший регистр количества шагов
  Wire.write(uint8_t((n_steps >> 8) & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x0F);       // Регистр количества повторов вращений
  Wire.write(0x01);       // Одна итерация
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x1A);       // Регистр запуска программы вращения
  Wire.write(0x80);       // Вращение по часовой стрелке
  Wire.endTransmission();
}

void motor_backward(uint8_t drv_addr, uint16_t n_steps, uint16_t m_speed)
{
  Wire.beginTransmission(drv_addr);
  Wire.write(0x18);       // Младший регистр ширины импульса управления мотором
  Wire.write(uint8_t(m_speed & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x19);       // Старший регистр ширины импульса управления мотором
  Wire.write(uint8_t((m_speed >> 8) & 0xFF | 0b10000000)); // Предделитель 0b100
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x14);       // Младший регистр количества шагов
  Wire.write(uint8_t(n_steps & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x15);       // Старший регистр количества шагов
  Wire.write(uint8_t((n_steps >> 8) & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x0F);       // Регистр количества повторов вращений
  Wire.write(0x01);       // Одна итерация
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x1A);       // Регистр запуска программы вращения
  Wire.write(0x81);       // Вращение по часовой стрелке
  Wire.endTransmission();
}

void motor_stop(uint8_t drv_addr)
{
  Wire.beginTransmission(drv_addr);
  Wire.write(0x1A);       // Регистр запуска программы вращения
  Wire.write(0x00);       // Вращение по часовой стрелке
  Wire.endTransmission();
}

uint8_t is_motor_running(uint8_t drv_addr)
{
  uint8_t rflag = 0;
  Wire.beginTransmission(drv_addr);
  Wire.write(0x1A);       // Регистр запуска программы вращения
  Wire.endTransmission();
  Wire.requestFrom(drv_addr, 1);
  if (Wire.available() == 1)
  {
    rflag = Wire.read();
  }
  rflag = (rflag >> 7) & 0x01;  // Проверка бита, отвечающего за запуск мотора
  return rflag;
}
