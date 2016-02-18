/*
  Пример работы с драйвером матрицы светодиодов MAX7219
  Created by Rostislav Varzar
*/

#include "LedControl.h"

LedControl lc = LedControl(12, 11, 10, 1);

// Смайлики
const byte PROGMEM smile_sad[8] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10011001,
  B10100101,
  B01000010,
  B00111100
};
const byte PROGMEM smile_neutral[8] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10000001,
  B10111101,
  B01000010,
  B00111100
};
const byte PROGMEM smile_happy[8] =
{
  B00111100,
  B01000010,
  B10100101,
  B10000001,
  B10100101,
  B10011001,
  B01000010,
  B00111100
};

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация матрицы
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void loop() {
  lc.setRow(0, 0, smile_sad[0]);
  lc.setRow(0, 1, smile_sad[1]);
  lc.setRow(0, 2, smile_sad[2]);
  lc.setRow(0, 3, smile_sad[3]);
  lc.setRow(0, 4, smile_sad[4]);
  lc.setRow(0, 5, smile_sad[5]);
  lc.setRow(0, 6, smile_sad[6]);
  lc.setRow(0, 7, smile_sad[7]);
  delay(500);
  lc.setRow(0, 0, smile_neutral[0]);
  lc.setRow(0, 1, smile_neutral[1]);
  lc.setRow(0, 2, smile_neutral[2]);
  lc.setRow(0, 3, smile_neutral[3]);
  lc.setRow(0, 4, smile_neutral[4]);
  lc.setRow(0, 5, smile_neutral[5]);
  lc.setRow(0, 6, smile_neutral[6]);
  lc.setRow(0, 7, smile_neutral[7]);
  delay(500);
  lc.setRow(0, 0, smile_happy[0]);
  lc.setRow(0, 1, smile_happy[1]);
  lc.setRow(0, 2, smile_happy[2]);
  lc.setRow(0, 3, smile_happy[3]);
  lc.setRow(0, 4, smile_happy[4]);
  lc.setRow(0, 5, smile_happy[5]);
  lc.setRow(0, 6, smile_happy[6]);
  lc.setRow(0, 7, smile_happy[7]);
  delay(500);
}
