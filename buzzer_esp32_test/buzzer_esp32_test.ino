/*
  Пример управления модулем звука (пьезодинамика)
  Created by Rostislav Varzar
*/

#define BUZZER_PIN 17

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация выхода
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);
}

int j = 30000;

void loop() {
  // Звук сирены
  for (int i = 0; i < (5 - j / 6000); i++) {
    digitalWrite(BUZZER_PIN, LOW);
    //delayMicroseconds(j);
    delay_nop(j);
    digitalWrite(BUZZER_PIN, HIGH);
    //delayMicroseconds(j);
    delay_nop(j);
  }
  j = j - 100;
  if (j <= 0) {
    j = 30000;
  }
}

// Задержка пустыми командами
void delay_nop(int u) {
  for (int i = 0; i < u; i++) {
    _NOP();
  }
}
