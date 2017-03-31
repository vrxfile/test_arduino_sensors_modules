/*
  Пример работы с УЗ датчиком расстояния HC-SR04
  Created by Rostislav Varzar
*/

#define sigPin A5
int maximumRange = 400;
int minimumRange = 0;
long duration = 0;
long distance = 0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
}

void loop() {
  // Измерение
  pinMode(sigPin, OUTPUT);
  digitalWrite(sigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sigPin, LOW);
  pinMode(sigPin, INPUT);
  duration = pulseIn(sigPin, HIGH);
  distance = duration / 58.2;
  if (distance >= maximumRange || distance <= minimumRange) {
    distance = -1;
  }
  // Вывод измеренных значений
  Serial.println("Distance: " + String(distance) + " cm");
  delay(100);
}
