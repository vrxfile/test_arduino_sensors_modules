/*
  Пример работы с приемником инфракрасных сигналов пульта и реле
  Created by Rostislav Varzar
*/

#include <IRremote.h>

#define RECV_PIN 6
#define RELAY_PIN 7

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация ИК приемника
  irrecv.enableIRIn();
  // Инициализация вывода реле
  digitalWrite(RELAY_PIN, true);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Чтение принятого сигнала
  if (irrecv.decode(&results))
  {
    // Вывод принятого кода
    Serial.println(results.value, HEX);
    // Включаем реле на 100 мс
    if (results.value)
    {
      digitalWrite(RELAY_PIN, false);
    }
    // Продолжение приема сигналов
    irrecv.resume();
  }
  delay(250);
  // Выключаем реле
  digitalWrite(RELAY_PIN, true);
}
