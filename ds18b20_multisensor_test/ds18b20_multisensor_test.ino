/*
  Пример работы с несколькими датчиками температуры DS18B20
  Created by Rostislav Varzar
*/

#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS1 A0
#define ONE_WIRE_BUS2 A1
#define ONE_WIRE_BUS3 A2
#define ONE_WIRE_BUS4 A3
#define ONE_WIRE_BUS5 A4
#define ONE_WIRE_BUS6 A5
#define ONE_WIRE_BUS7 2
#define ONE_WIRE_BUS8 3
#define ONE_WIRE_BUS9 4

OneWire oneWire1(ONE_WIRE_BUS1);
OneWire oneWire2(ONE_WIRE_BUS2);
OneWire oneWire3(ONE_WIRE_BUS3);
OneWire oneWire4(ONE_WIRE_BUS4);
OneWire oneWire5(ONE_WIRE_BUS5);
OneWire oneWire6(ONE_WIRE_BUS6);
OneWire oneWire7(ONE_WIRE_BUS7);
OneWire oneWire8(ONE_WIRE_BUS8);
OneWire oneWire9(ONE_WIRE_BUS9);

DallasTemperature ds_sensor1(&oneWire1);
DallasTemperature ds_sensor2(&oneWire2);
DallasTemperature ds_sensor3(&oneWire3);
DallasTemperature ds_sensor4(&oneWire4);
DallasTemperature ds_sensor5(&oneWire5);
DallasTemperature ds_sensor6(&oneWire6);
DallasTemperature ds_sensor7(&oneWire7);
DallasTemperature ds_sensor8(&oneWire8);
DallasTemperature ds_sensor9(&oneWire9);

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация датчиков
  ds_sensor1.begin();
  ds_sensor2.begin();
  ds_sensor3.begin();
  ds_sensor4.begin();
  ds_sensor5.begin();
  ds_sensor6.begin();
  ds_sensor7.begin();
  ds_sensor8.begin();
  ds_sensor9.begin();
}

void loop() {
  // Измерение на всех датчиках
  ds_sensor1.requestTemperatures();
  ds_sensor2.requestTemperatures();
  ds_sensor3.requestTemperatures();
  ds_sensor4.requestTemperatures();
  ds_sensor5.requestTemperatures();
  ds_sensor6.requestTemperatures();
  ds_sensor7.requestTemperatures();
  ds_sensor8.requestTemperatures();
  ds_sensor9.requestTemperatures();
  float t1 = ds_sensor1.getTempCByIndex(0);
  float t2 = ds_sensor2.getTempCByIndex(0);
  float t3 = ds_sensor3.getTempCByIndex(0);
  float t4 = ds_sensor4.getTempCByIndex(0);
  float t5 = ds_sensor5.getTempCByIndex(0);
  float t6 = ds_sensor6.getTempCByIndex(0);
  float t7 = ds_sensor7.getTempCByIndex(0);
  float t8 = ds_sensor8.getTempCByIndex(0);
  float t9 = ds_sensor9.getTempCByIndex(0);
  // Вывод измеренных значений
  Serial.println("Temperature 1: " + String(t1, 2) + " *C");
  Serial.println("Temperature 2: " + String(t2, 2) + " *C");
  Serial.println("Temperature 3: " + String(t3, 2) + " *C");
  Serial.println("Temperature 4: " + String(t4, 2) + " *C");
  Serial.println("Temperature 5: " + String(t5, 2) + " *C");
  Serial.println("Temperature 6: " + String(t6, 2) + " *C");
  Serial.println("Temperature 7: " + String(t7, 2) + " *C");
  Serial.println("Temperature 8: " + String(t8, 2) + " *C");
  Serial.println("Temperature 9: " + String(t9, 2) + " *C");
  Serial.println();
  delay(1000);
}
