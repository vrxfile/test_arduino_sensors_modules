/*
  Пример управления модулем RGB светодиода
  Created by Rostislav Varzar
*/

#define R_LED 3
#define G_LED 5
#define B_LED 6

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выходов на светодиоды
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
}

void loop() {
  // Красный
  digitalWrite(R_LED, HIGH);
  digitalWrite(G_LED, LOW);
  digitalWrite(B_LED, LOW);
  delay(1000);
  // Зеленый
  digitalWrite(R_LED, LOW);
  digitalWrite(G_LED, HIGH);
  digitalWrite(B_LED, LOW);
  delay(1000);
  // Синий
  digitalWrite(R_LED, LOW);
  digitalWrite(G_LED, LOW);
  digitalWrite(B_LED, HIGH);
  delay(1000);
  // Желтый
  digitalWrite(R_LED, HIGH);
  digitalWrite(G_LED, HIGH);
  digitalWrite(B_LED, LOW);
  delay(1000);
  // Розовый
  digitalWrite(R_LED, HIGH);
  digitalWrite(G_LED, LOW);
  digitalWrite(B_LED, HIGH);
  delay(1000);
  // Бирюзовый
  digitalWrite(R_LED, LOW);
  digitalWrite(G_LED, HIGH);
  digitalWrite(B_LED, HIGH);
  delay(1000);
  // Белый
  digitalWrite(R_LED, HIGH);
  digitalWrite(G_LED, HIGH);
  digitalWrite(B_LED, HIGH);
  delay(1000);
  // Плавное увеличение и уменьшение яркости всех трех цветов
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(R_LED, i);
    analogWrite(G_LED, i);
    analogWrite(B_LED, i);
    delay(10);
  }
  for (int i = 255; i >= 0; i--)
  {
    analogWrite(R_LED, i);
    analogWrite(G_LED, i);
    analogWrite(B_LED, i);
    delay(10);
  }
  delay(1000);
  // Выключены все светодиоды
  digitalWrite(R_LED, LOW);
  digitalWrite(G_LED, LOW);
  digitalWrite(B_LED, LOW);
  delay(1000);
}
