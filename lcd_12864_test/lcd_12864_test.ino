/*
  Пример работы с LCD дисплеем LCM12864
  Created by Rostislav Varzar
*/

#include "U8glib.h"

// SPI Com: SCK = 8, MOSI = 7, CS = 6, A0 = 5, RST = 4
U8GLIB_NHD_C12864 u8g(8, 7, 6, 5, 4);

void setup(void) {
  // Установка контрастности
  u8g.setContrast(0);
  // Установка цвета линий
  u8g.setColorIndex(1);
  // Установка шрифта
  u8g.setFont(u8g_font_timB18);
}

void loop(void) {
  u8g.firstPage();
  // Цикл рисования
  do {
    // Вывод текста
    u8g.drawStr(20, 35, "MGBot");
  } while (u8g.nextPage());
}

