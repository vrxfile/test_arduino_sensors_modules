/*
  Пример работы с датчиком цвета TCS230
  Created by Rostislav Varzar
*/

#define S0PIN 2
#define S1PIN 3
#define S2PIN 8
#define S3PIN 11
#define OUTPIN 12

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
}

void loop() {
  // Измерение
  float clRed = 1000 / (float)readRED();
  float clGreen = 1000 / (float)readGREEN();
  float clBlue = 1000 / (float)readBLUE();
  float clClear = 1000 / (float)readCLEAR();
  String MY_COLOR = "";
  // Вывод интенсивности цветов
  Serial.println("RED: " + String(clRed, 3));
  Serial.println("GREEN: " + String(clGreen, 3));
  Serial.println("BLUE: " + String(clBlue, 3));
  Serial.println("CLEAR: " + String(clClear, 3));
  Serial.println();
  // Определение цвета кубика
  if ((clRed > 0.600) && (clRed < 0.900) && (clGreen > 0.900) && (clGreen < 1.200) && (clBlue > 3.900) && (clBlue < 4.200))
  {
    MY_COLOR = "BLUE";
  }
  else if ((clRed > 0.700) && (clRed < 1.000) && (clGreen > 1.000) && (clGreen < 1.300) && (clBlue > 3.000) && (clBlue < 3.300))
  {
    MY_COLOR = "GREEN";
  }
  else if ((clRed > 2.900) && (clRed < 3.200) && (clGreen > 0.600) && (clGreen < 0.900) && (clBlue > 4.450) && (clBlue < 4.750))
  {
    MY_COLOR = "RED";
  }
  else if ((clRed > 4.050) && (clRed < 4.350) && (clGreen > 2.500) && (clGreen < 2.800) && (clBlue > 8.550) && (clBlue < 8.850))
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

