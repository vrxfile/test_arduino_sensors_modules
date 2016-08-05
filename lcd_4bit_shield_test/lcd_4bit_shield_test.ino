/*
  Пример работы с платой LCD Shield
  Created by Rostislav Varzar
*/

#include <LiquidCrystal.h>

/*
  The circuit:
   LCD RS pin to digital pin 8
   LCD Enable pin to digital pin 9
   LCD D4 pin to digital pin 4
   LCD D5 pin to digital pin 5
   LCD D6 pin to digital pin 6
   LCD D7 pin to digital pin 7
   LCD R/W pin to ground
   LCD VSS pin to ground
   LCD VCC pin to 5V
*/

// Определение объекта LCD
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// Подсветка LCD
#define LCD_LIGHT 10

#define KEYBOARD A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация подсветки LCD
  pinMode(LCD_LIGHT, OUTPUT);
  //analogWrite(LCD_LIGHT, 127); // Плавное управление
  digitalWrite(LCD_LIGHT, true);
  // Инициализация LCD
  lcd.begin(16, 2);
}

void loop() {
  // Определяем номер нажатой кнопки
  int key_number = read_keyboard();
  // Устанавливаем позицию курсора
  lcd.setCursor(0, 0);
  // Выводим номер нажатой кнопки на LCD
  lcd.print("BUTTON #: " + String(key_number) + "   ");
  delay(100);
}

// Определение номера нажатой кнопки на клавиатуре
int read_keyboard() {
  int sensor_data = analogRead(KEYBOARD);
  if (sensor_data < 20) {
    return 1;
  } else if ((sensor_data > 130) && (sensor_data < 150)) {
    return 2;
  } else if ((sensor_data > 300) && (sensor_data < 320)) {
    return 3;
  } else if ((sensor_data > 475) && (sensor_data < 495)) {
    return 4;
  } else if ((sensor_data > 715) && (sensor_data < 735)) {
    return 5;
  } else {
    return 0;
  }
}

