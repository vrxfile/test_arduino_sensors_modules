/*
  Пример работы с датчиком цвета TCS230
  Created by Rostislav Varzar
*/

#define S0PIN 2
#define S1PIN 3
#define S2PIN 8
#define S3PIN 11
#define OUTPIN 12

float r0, g0, b0, c0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация выводов для управления датчиком
  pinMode(S0PIN, OUTPUT);
  pinMode(S1PIN, OUTPUT);
  pinMode(S2PIN, OUTPUT);
  pinMode(S3PIN, OUTPUT);
  pinMode(OUTPIN, INPUT);
  digitalWrite(S0PIN, LOW);
  digitalWrite(S1PIN, HIGH);
  // Нахождениен коэффициентов для исключения сперктальной характеристики окружающего света
  r0 = 1000 / (float)readRED();
  g0 = 1000 / (float)readGREEN();
  b0 = 1000 / (float)readBLUE();
  c0 = 1000 / (float)readCLEAR();
}

void loop() {
  // Измерение
  float clRed = 1000 / (float)readRED() - r0;
  float clGreen = 1000 / (float)readGREEN() - g0;
  float clBlue = 1000 / (float)readBLUE() - b0;
  float clClear = 1000 / (float)readCLEAR() - c0;
  String MY_COLOR = "";
  // Вывод интенсивности цветов
  Serial.println("RED: " + String(clRed, 3));
  Serial.println("GREEN: " + String(clGreen, 3));
  Serial.println("BLUE: " + String(clBlue, 3));
  Serial.println("CLEAR: " + String(clClear, 3));
  Serial.println();
  // Определение цвета кубика
  if ((clRed > -0.400) && (clRed < 0.400) && (clGreen > 0.200) && (clGreen < 1.000) && (clBlue > 1.300) && (clBlue < 2.100))
  {
    MY_COLOR = "BLUE";
  }
  else if ((clRed > -0.300) && (clRed < 0.500) && (clGreen > 0.300) && (clGreen < 1.100) && (clBlue > 0.200) && (clBlue < 1.000))
  {
    MY_COLOR = "GREEN";
  }
  else if ((clRed > 1.900) && (clRed < 2.700) && (clGreen > -0.100) && (clGreen < 0.700) && (clBlue > 0.200) && (clBlue < 1.000))
  {
    MY_COLOR = "RED";
  }
  else if ((clRed > 2.900) && (clRed < 3.700) && (clGreen > 1.800) && (clGreen < 2.600) && (clBlue > 0.600) && (clBlue < 1.400))
  {
    MY_COLOR = "YELLOW";
  }
  else
  {
    MY_COLOR = "UNDEFINED";
  }
  Serial.println("Color: " + MY_COLOR);
  Serial.println();
  delay(1000);
}

// Чтение интенсивности красного цвета
int readRED()
{
  digitalWrite(S2PIN, LOW);
  digitalWrite(S3PIN, LOW);
  return pulseIn(OUTPIN, digitalRead(OUTPIN) == HIGH ? LOW : HIGH);
}

// Чтение интенсивности зеленого цвета
int readGREEN()
{
  digitalWrite(S2PIN, HIGH);
  digitalWrite(S3PIN, HIGH);
  return pulseIn(OUTPIN, digitalRead(OUTPIN) == HIGH ? LOW : HIGH);
}

// Чтение интенсивности синего цвета
int readBLUE()
{
  digitalWrite(S2PIN, LOW);
  digitalWrite(S3PIN, HIGH);
  return pulseIn(OUTPIN, digitalRead(OUTPIN) == HIGH ? LOW : HIGH);
}

// Чтение интенсивности без фильтров
int readCLEAR()
{
  digitalWrite(S2PIN, HIGH);
  digitalWrite(S3PIN, LOW);
  return pulseIn(OUTPIN, digitalRead(OUTPIN) == HIGH ? LOW : HIGH);
}


