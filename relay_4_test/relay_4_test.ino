/*
  Пример управления модулем четырех реле
  Created by Rostislav Varzar
*/

#define RELAYPIN1 12
#define RELAYPIN2 11
#define RELAYPIN3 10
#define RELAYPIN4 9

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выходов для реле
  pinMode(RELAYPIN1, OUTPUT);
  pinMode(RELAYPIN2, OUTPUT);
  pinMode(RELAYPIN3, OUTPUT);
  pinMode(RELAYPIN4, OUTPUT);
}

void loop() {
  // Включение реле методом бегущих огней
  digitalWrite(RELAYPIN1, HIGH);
  digitalWrite(RELAYPIN2, LOW);
  digitalWrite(RELAYPIN3, LOW);
  digitalWrite(RELAYPIN4, LOW);
  delay(250);
  digitalWrite(RELAYPIN1, LOW);
  digitalWrite(RELAYPIN2, HIGH);
  digitalWrite(RELAYPIN3, LOW);
  digitalWrite(RELAYPIN4, LOW);
  delay(250);
  digitalWrite(RELAYPIN1, LOW);
  digitalWrite(RELAYPIN2, LOW);
  digitalWrite(RELAYPIN3, HIGH);
  digitalWrite(RELAYPIN4, LOW);
  delay(250);
  digitalWrite(RELAYPIN1, LOW);
  digitalWrite(RELAYPIN2, LOW);
  digitalWrite(RELAYPIN3, LOW);
  digitalWrite(RELAYPIN4, HIGH);
  delay(250);
}
