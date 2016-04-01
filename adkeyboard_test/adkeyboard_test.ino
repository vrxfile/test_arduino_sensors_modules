/*
  Пример работы с аналоговой кнопочной клавиатурой ADKeyBoard
  Created by Rostislav Varzar
*/

#define SENSPIN A0

void setup() {
  // Инициализация последовательного порта
  Serial.begin(9600);
  // Инициализация входа аналогового датчика
  pinMode(SENSPIN, INPUT);
}

void loop() {
  // Измерение
  int sensor_data = analogRead(SENSPIN);
  // Опредление номера нажатой кнопки
  if (sensor_data < 20)
  {
    Serial.println("Button SW1 pressed");
  }
  else if ((sensor_data > 130) && (sensor_data < 150))
  {
    Serial.println("Button SW2 pressed");
  }
  else if ((sensor_data > 320) && (sensor_data < 340))
  {
    Serial.println("Button SW3 pressed");
  }
  else if ((sensor_data > 495) && (sensor_data < 515))
  {
    Serial.println("Button SW4 pressed");
  }
  else if ((sensor_data > 730) && (sensor_data < 750))
  {
    Serial.println("Button SW5 pressed");
  }
  delay(100);
}
