/*
  Пример работы с моторным драйвером PCA9629A
  Created by Rostislav Varzar
*/
#include <Wire.h>

#define driver_addr1 0x20

uint8_t m_ctl = 0b00000000;

void setup() 
{
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация датчика
  init_driver(driver_addr1);
  delay(500);
  // motor1_backward(); delay(500);
  motor1_forward(driver_addr1, 1000, 8); delay(500);
  // motor1_stop(); delay(500);
}

void loop() 
{
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

void motor1_forward(uint8_t drv_addr, uint16_t n_steps, uint16_t m_speed)
{
  Wire.beginTransmission(drv_addr);
  Wire.write(0x16);       // Младший регистр ширины импульса управления мотором
  Wire.write(uint8_t(m_speed & 0xFF));
  Wire.endTransmission();
  Wire.beginTransmission(drv_addr);
  Wire.write(0x17);       // Старший регистр ширины импульса управления мотором
  Wire.write(uint8_t((m_speed >> 8) & 0xFF | 0b11100000)); // Предделитель 0b111
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


void motor1_backward(uint8_t drv_addr, uint16_t n_steps, uint16_t m_speed)
{
  Wire.beginTransmission(drv_addr);
  Wire.write(0x0B);
  Wire.write(m_ctl);
  Wire.endTransmission();
}

void motor1_stop(uint8_t drv_addr)
{
}
