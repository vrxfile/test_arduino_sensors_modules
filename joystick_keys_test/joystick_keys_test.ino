/*
  Пример работы с джойстиком и четырьмя кнопками
  Created by Rostislav Varzar
*/

#define SK A0
#define SY A1
#define SX A2

#define SW1 10
#define SW2 11
#define SW3 12
#define SW4 13

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входов
  pinMode(SK, INPUT);
  pinMode(SY, INPUT);
  pinMode(SX, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
}

void loop() {
  int sk = digitalRead(SK);
  int sy = analogRead(SY);
  int sx = analogRead(SX);
  int sw1 = digitalRead(SW1);
  int sw2 = digitalRead(SW2);
  int sw3 = digitalRead(SW3);
  int sw4 = digitalRead(SW4);
  Serial.print(sw1); Serial.print("\t");
  Serial.print(sw2); Serial.print("\t");
  Serial.print(sw3); Serial.print("\t");
  Serial.print(sw4); Serial.print("\t");
  Serial.print(sk); Serial.print("\t");
  Serial.print(sx); Serial.print("\t");
  Serial.print(sy); Serial.print("\n");
  delay(100);
}
