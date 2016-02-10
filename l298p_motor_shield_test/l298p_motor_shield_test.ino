/*
  Пример работы с платой L298P Drive Shield V1
  Created by Rostislav Varzar
*/

#define PWMA 5
#define DIRA 4
#define PWMB 6
#define DIRB 7

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выходов для управления моторами
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
}

void loop() {
  int value;
  // Плавно увеличиваем мощность в одну сторону
  for (value = 0 ; value <= 100; value += 1)
  {
    motorA_setpower(value);
    motorB_setpower(value);
    Serial.println("Power: " + String(value) + " %");
    delay(50);
  }
  // Плавно уменьшаем мощность, переходим 0 и начинаем вращать в другую сторону
  for (value = 100 ; value >= -100; value -= 1)
  {
    motorA_setpower(value);
    motorB_setpower(value);
    Serial.println("Power: " + String(value) + " %");
    delay(50);
  }
  // Плавно уменьшаем мощность
  for (value = -100 ; value <= 0; value += 1)
  {
    motorA_setpower(value);
    motorB_setpower(value);
    Serial.println("Power: " + String(value) + " %");
    delay(50);
  }
}

// Мощность мотора "A" от -100% до +100% (от знака зависит направление вращения)
void motorA_setpower(int pwr)
{
  // Проверка диапазонов
  if (pwr < -100)
  {
    pwr = -100;
  }
  if (pwr > 100)
  {
    pwr = 100;
  }
  // Установка направления
  if (pwr < 0)
  {
    digitalWrite(DIRA, LOW);
  }
  else
  {
    digitalWrite(DIRA, HIGH);
  }
  // Установка мощности
  int pwmvalue = abs(pwr) * 2.55;
  analogWrite(PWMA, pwmvalue);
}

// Мощность мотора "B" от -100% до +100% (от знака зависит направление вращения)
void motorB_setpower(int pwr)
{
  // Проверка диапазонов
  if (pwr < -100)
  {
    pwr = -100;
  }
  if (pwr > 100)
  {
    pwr = 100;
  }
  // Установка направления
  if (pwr < 0)
  {
    digitalWrite(DIRB, LOW);
  }
  else
  {
    digitalWrite(DIRB, HIGH);
  }
  // Установка мощности
  int pwmvalue = abs(pwr) * 2.55;
  analogWrite(PWMB, pwmvalue);
}

