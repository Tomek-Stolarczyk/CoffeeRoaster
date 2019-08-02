#include "ManualController.h"


enum class UpdatableComponents{
  MANUALCONTROLLER = 0,
  THERMOCOUPLE = 1,
  NUMBEROFCOMPONENTS
};

void setup() {
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(500);
}

// int fan_speed = 255;
// int modifier = -10;

// void Coffee_loop()
// {
//   //Serial.println(fan_speed);
//   SetFanSpeed(fan_speed);
//   char message[256];
//   double curr_temp = thermocouple.readCelsius();
//   double derivative = CalculateDerivative(curr_temp);
//   //addToRingBuffer(curr_temp);
//   char curr_temp_s[10];
//   char derivative_s[10];
//   dtostrf(curr_temp, 4, 4, curr_temp_s);
//   dtostrf(derivative, 4, 6, derivative_s);
//   sprintf(message, "%s, %s, %d", curr_temp_s, derivative_s, fan_speed);
//   Serial.println(message);
//   delay(200);
// }


void Testing_loop()
{

  auto value = analogRead(A0);
  String message = "Hello " + String(value);
  Serial.println(message);
}

void loop() {
  Testing_loop();
}
