/*
  Пример работы с двумя джойстиками
  Created by Rostislav Varzar
*/

#define SK1 10
#define SX1 A0
#define SY1 A1

#define SK2 11
#define SX2 A2
#define SY2 A3

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входов
  pinMode(SK1, INPUT);
  pinMode(SX1, INPUT);
  pinMode(SY1, INPUT);
  pinMode(SK2, INPUT);
  pinMode(SX2, INPUT);
  pinMode(SY2, INPUT);
}

void loop() {
  int sk1 = digitalRead(SK1);
  int sx1 = analogRead(SX1);
  int sy1 = analogRead(SY1);
  int sk2 = digitalRead(SK2);
  int sx2 = analogRead(SX2);
  int sy2 = analogRead(SY2);
  Serial.print(sk1); Serial.print("\t");
  Serial.print(sx1); Serial.print("\t");
  Serial.print(sy1); Serial.print("\t");
  Serial.print(sk2); Serial.print("\t");
  Serial.print(sx2); Serial.print("\t");
  Serial.print(sy2); Serial.print("\n");
  delay(100);
}
