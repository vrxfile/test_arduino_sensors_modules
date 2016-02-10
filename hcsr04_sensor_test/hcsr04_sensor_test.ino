/*
  Пример работы с УЗ датчиком расстояния HC-SR04
  Created by Rostislav Varzar
*/

#define trigPin 11
#define echoPin 12
int maximumRange = 200;
int minimumRange = 0;
long duration = 0;
long distance = 0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выводов для работы с УЗ датчиком
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Измерение
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
  if (distance >= maximumRange || distance <= minimumRange) {
    distance = -1;
  }
  // Вывод измеренных значений
  Serial.println("Distance: " + String(distance) + " cm");
  delay(100);
}
