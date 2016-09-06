/*
  Пример работы с клавиатурой 4x4
  Created by Rostislav Varzar
*/

#include <Keypad.h>

const byte ROWS = 4; // Количество строк
const byte COLS = 4; // Количество столбцов

// Карта символов
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5}; // Выводы строк
byte colPins[COLS] = {6, 7, 8, 9}; // Выводы столбцов

// Инициализация клавиатуры
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
}

void loop() {
  // Чтение текущего символа
  char customKey = customKeypad.getKey();
  // Вывод в терминал
  if (customKey) {
    Serial.println(customKey);
  }
}
