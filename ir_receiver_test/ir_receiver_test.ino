/*
  Пример работы с приемником инфракрасных сигналов пульта
  Created by Rostislav Varzar
*/

#include <IRremote.h>

#define RECV_PIN 6

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация ИК приемника
  irrecv.enableIRIn();
}

void loop() {
  // Чтение принятого сигнала
  if (irrecv.decode(&results))
  {
    // Вывод принятого кода
    Serial.println(results.value, HEX);
    // Продолжение приема сигналов
    irrecv.resume();
  }
  delay(100);
}
