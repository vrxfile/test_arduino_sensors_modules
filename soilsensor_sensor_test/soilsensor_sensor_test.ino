/*
  Пример работы с модулем аналогового емкостного датчика влажности и температуры почвы
  Created by Rostislav Varzar
*/
#define SOIL_MOISTURE    A0
#define SOIL_TEMPERATURE A1
const float air_value = 551.0;
const float water_value = 293.0;
const float moisture_0 = 0.0;
const float moisture_100 = 100.0;

void setup() {
  // Инициализация последовательного порта
  Serial.begin(115200);
}

void loop() {
  // Измерение
  float adc0 = analogRead(SOIL_MOISTURE);
  float adc1 = analogRead(SOIL_TEMPERATURE);
  float t = ((adc1 / 1023.0 * 5.0) - 0.5) * 100.0;
  float h = map(adc0, air_value, water_value, moisture_0, moisture_100);
  // Вывод измеренных значений в терминал
  Serial.println("Soil humidity = " + String(h, 1) + " %");
  Serial.println("Soil temperature = " + String(t, 1) + " *C");
  delay(250);
}
