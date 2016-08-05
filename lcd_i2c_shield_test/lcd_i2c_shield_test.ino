/*
  Пример работы с платой LCD LCM1602 IIC Shield V1
  Created by Rostislav Varzar
*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define KEYBOARD A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация дисплея
  lcd.init();       // Инициализация
  lcd.backlight();  // Включение подсветки
  lcd.clear();      // Очистка экрана
}

void loop() {
  // Определяем номер нажатой кнопки
  int key_number = read_keyboard();
  // Устанавливаем позицию курсора
  lcd.setCursor(0, 0);
  // Выводим номер нажатой кнопки на LCD
  lcd_printstr("BUTTON #: " + String(key_number) + "   ");
  delay(100);
}

// Функция вывода текстовой строки на дисплей
void lcd_printstr(String str1) {
  for (int i = 0; i < str1.length(); i++) {
    lcd.print(str1.charAt(i));
  }
}

// Определение номера нажатой кнопки на клавиатуре
int read_keyboard() {
  int sensor_data = analogRead(KEYBOARD);
  if (sensor_data < 20) {
    return 1;
  } else if ((sensor_data > 130) && (sensor_data < 150)) {
    return 2;
  } else if ((sensor_data > 315) && (sensor_data < 335)) {
    return 3;
  } else if ((sensor_data > 490) && (sensor_data < 510)) {
    return 4;
  } else if ((sensor_data > 730) && (sensor_data < 750)) {
    return 5;
  } else {
    return 0;
  }
}

