/*
  Пример работы с сервомоторами
  Created by Rostislav Varzar
*/

#include <Servo.h>

#define SERVO1_PWM 9
#define SERVO2_PWM 10

Servo servo_1;
Servo servo_2;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация портов для управления сервомоторами
  servo_1.attach(SERVO1_PWM);
  servo_2.attach(SERVO2_PWM);
}

void loop() {
  int angle;
  // Плавно вращаем в одну сторону
  for (angle = 0 ; angle <= 180; angle += 1)
  {
    servo_1.write(angle);
    servo_2.write(angle);
    Serial.println("Angle: " + String(angle) + " degrees");
    delay(50);
  }
  // // Плавно вращаем обратно
  for (angle = 180 ; angle >= 0; angle -= 1)
  {
    servo_1.write(angle);
    servo_2.write(angle);
    Serial.println("Angle: " + String(angle) + " degrees");
    delay(50);
  }
}
