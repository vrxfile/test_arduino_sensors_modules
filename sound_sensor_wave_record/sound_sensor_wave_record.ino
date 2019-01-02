/*
  Пример работы с модулем цифрового датчика звука (запись звука), пока плохо работает режим записи на SD карту
  Created by Rostislav Varzar
*/
#include <Wire.h>
#include "MCP3221.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "Wav.h"

const byte DEV_ADDR = 0x48;  // Адрес микросхемы A0

const int record_time = 1;  // Время записи в секундах
const char filename[] = "/sound_1.wav";

const int headerSize = 44;
const long waveDataSize = record_time * 44100 * 2;
byte header[headerSize];
byte partWavData[2];
File wavfile;

MCP3221 mcp3221(DEV_ADDR);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
  // Инициализация I2C интерфейса
  Wire.begin();
  Wire.setClock(400000L);
  // Инициализация SD карты
  if (!SD.begin()) {
    Serial.println("Card Mount Failed");
    return;
  }
  // Тип карты памяти
  uint8_t cardType = SD.cardType();
  if (cardType == CARD_NONE) {
    Serial.println("No SD_MMC card attached");
    return;
  }
  Serial.print("SD_MMC Card Type: ");
  if (cardType == CARD_MMC) {
    Serial.println("MMC");
  } else if (cardType == CARD_SD) {
    Serial.println("SDSC");
  } else if (cardType == CARD_SDHC) {
    Serial.println("SDHC");
  } else {
    Serial.println("UNKNOWN");
  }
  // Размер карты памяти
  uint64_t cardSize = SD.cardSize() / (1024 * 1024);
  Serial.printf("SD_MMC Card Size: %lluMB\n", cardSize);
}

void loop() {
  // Тест скорости записи
  mcp3221.setAlpha(MIN_ALPHA);
  mcp3221.setNumSamples(MIN_NUM_SAMPLES);
  mcp3221.setSmoothing(NO_SMOOTHING);
  Serial.println("Alpha = " + String(mcp3221.getAlpha()));
  Serial.println("NumSamples = " + String(mcp3221.getNumSamples()));
  Serial.println("Smoothing = " + String(mcp3221.getSmoothing()));
  Serial.println("Data = " + String(mcp3221.getData() * 10));
  float st = millis();
  for (long j = 0; j < 10000; j++) {
    unsigned int adc0 = mcp3221.getData() * 10;
    partWavData[0] = (byte)(adc0 & 0xFF);
    partWavData[1] = (byte)(adc0 >> 8) & 0xFF;
    //Serial.print(j);
    //Serial.print(" ");
    //Serial.println(adc0);
  }
  float tm = millis() - st;
  float bitrate = 10000.0 / tm * 1000.0;
  Serial.println("Time = " + String(tm, 1) + " ms");
  Serial.println("Bitrate = " + String(bitrate, 1) + " sps");
  while (1) {
    delay(1000);
  }
  // Удаление старого WAV файла
  SD.remove(filename);
  // Создание заголовка WAV файла
  CreateWavHeader(header, waveDataSize);
  // Открытие WAV файла для записи
  wavfile = SD.open(filename, FILE_WRITE);
  if (!wavfile) {
    Serial.println("Error opening file!");
    return;
  }
  // Запись заголовка WAV файла
  wavfile.write(header, headerSize);
  // Запись звука
  Serial.println("Record started");
  for (long j = 0; j < (waveDataSize / 2); ++j) {
    unsigned int adc0 = mcp3221.getVoltage();
    partWavData[0] = (byte)(adc0 & 0xFF);
    partWavData[1] = (byte)(adc0 >> 8) & 0xFF;
    wavfile.write((const byte*)partWavData, 2);
  }
  // Закрытие файла
  wavfile.close();
  Serial.println("Record finished");
  /*
    // Запись звука
    Serial.println("Record started");
    for (long j = 0; j < (waveDataSize / 2); ++j) {
    unsigned int adc0 = mcp3221.getVoltage();
    partWavData[2 * j] = (byte)(adc0 & 0xFF);
    partWavData[2 * j + 1] = (byte)(adc0 >> 8) & 0xFF;
    }
    Serial.println("Record finished");
    // Удаление старого WAV файла
    SD_MMC.remove(filename);
    // Создание заголовка WAV файла
    CreateWavHeader(header, waveDataSize);
    // Открытие WAV файла для записи
    wavfile = SD_MMC.open(filename, FILE_WRITE);
    if (!wavfile) {
    Serial.println("Error opening file!");
    return;
    }
    // Запись заголовка WAV файла
    wavfile.write(header, headerSize);
    wavfile.write((const byte*)partWavData, waveDataSize);
    // Закрытие файла
    wavfile.close();
  */
  while (1) {
    delay(1000);
  }
}
