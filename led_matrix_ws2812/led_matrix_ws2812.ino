/*
  Пример работы с RGB драйвером матрицы светодиодов WS2812
  При использовании данного примера, сигнальный вход матрицы подключать к порту D8
  Created by Rostislav Varzar
*/
#include "HCWS2812.h"

// Количество светодиодов в матрице
#define NUMBEROFLEDS 64

HCWS2812 HCWS2812_MATRIX;

void setup() {
  // Очистка выходного буфера
  HCWS2812_MATRIX.ClearBuffer();
  // Установка черного цвета фона
  HCWS2812_MATRIX.SetBG(0, 0, 0);
}

void loop() {
  // Установка случайного цвета шрифта
  HCWS2812_MATRIX.SetFontFG(random(0, 100), random(0, 100), random(0, 100));
  // Выводим бегущую строку
  for (int i = 0; i < 48; i++)
  {
    HCWS2812_MATRIX.print("MGBOT", i);
    HCWS2812_MATRIX.Refresh();
    delay(50);
  }
}
