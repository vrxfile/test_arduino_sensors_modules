/*
  Пример получения списка файлов с SD карты
  Основано на примерах Arduino
  Created by Rostislav Varzar
*/

#include <SD.h>
#include <SPI.h>

File root;

#define CS_PIN 4

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация карты памяти
  if (!SD.begin(CS_PIN))
  {
    Serial.println("SD card initialization failed!");
    return;
  }
  // Переход в корневой каталог
  root = SD.open("/");
}

void loop() {
  // Печать списка файлов
  printDirectory(root, 0);
  root.close();
  while (true)
  {
  }
}

// Функция скинирования директорий, поиска файлов и вывода списка
// Взята из примеров для Arduino
void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println("/");
      printDirectory(entry, numTabs + 1);
    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}


