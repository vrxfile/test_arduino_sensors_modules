/*
  Пример работы с модулем цифрового датчика звука (срабатывание реле по превышению порога громкости)
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include "MCP3221.h"

const byte DEV_ADDR = 0x48;  // Адрес микросхемы A0

#define RELAY_PIN 16 // Выход реле

MCP3221 mcp3221(DEV_ADDR);

int rstate = 1; // Реле выключено

int snd0 = 0;         // Состояние тишины
const int edge = 300; // Порог срабатывания

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация I2C интерфейса
  Wire.begin();
  // Инициализация реле
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, rstate);
  // Начальное состояние датчика звука
  snd0 = mcp3221.getVoltage();
}

void loop() {
  // Измерение
  int adc0 = mcp3221.getVoltage();
  // Вывод измеренных значений в терминал
  Serial.println("Sound level = " + String(adc0, 10));
  // Проверка порога срабатывания
  if (abs(adc0 - snd0) > edge) {
    rstate = 1 - rstate;
    digitalWrite(RELAY_PIN, rstate);
    delay(200);
  }
  delay(50);
}
