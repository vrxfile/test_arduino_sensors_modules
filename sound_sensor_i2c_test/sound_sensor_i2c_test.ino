/*
  Пример работы с модулем цифрового датчика звука
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include "MCP3221.h"

const byte DEV_ADDR = 0x48;  // Адрес микросхемы A0

MCP3221 mcp3221(DEV_ADDR);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация I2C интерфейса
  Wire.begin();
}

void loop() {
  // Измерение
  float adc0 = mcp3221.getVoltage();
  // Вывод измеренных значений в терминал
  Serial.println("Sound level = " + String(adc0, 1));
  delay(50);
}
