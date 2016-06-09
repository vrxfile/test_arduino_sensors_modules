/*
  Пример работы с моторным энкодером и платой Digit Shield
  Created by Rostislav Varzar
*/

#include <Encoder.h>
#include <DigitShield.h>

// Объект для работы с энкодером
Encoder myEnc(10, 11);

// Старое положение энкодера
long oldPosition  = 0;

// Новое положение энкодера
long newPosition  = 0;

void setup()
{
  // Инициализация цифрового дисплея
  DigitShield.begin();
  DigitShield.setPrecision(0);
  DigitShield.setValue(0);
}

void loop()
{
  // Чтение энкодера
  newPosition = myEnc.read();
  // Вывод положения энкодера на дисплей, если оно изменилось
  if (newPosition != oldPosition)
  {
    oldPosition = newPosition;
    DigitShield.setValue(double(abs(newPosition)));
  }
}
