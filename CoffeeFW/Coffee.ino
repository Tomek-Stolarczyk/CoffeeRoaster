#include "ManualController.h"


enum class UpdatableComponents{
  MANUALCONTROLLER = 0,
  NUMBEROFCOMPONENTS
};

void setup() {
  Serial.begin(19200);
  pinMode(LED_BUILTIN, OUTPUT);
  delay(500);
}

// #define kNumOfRecords 10
// double temp_records[kNumOfRecords];
// int temp_records_location = 0;

// double deriv_records[kNumOfRecords];
// int deriv_records_location = 0;s

// void addToTempRingBuffer(double temp){
//   if(records_location / kNumOfRecords == 1){
//     records_location = 0;
//   }

//   temp_records[records_location] = temp;
//   records_location++;
// }

// void addToDerivRingBuffer(double temp){
//   if(records_location / kNumOfRecords == 1){
//     records_location = 0;
//   }

//   deriv_records[records_location] = temp;
//   records_location++;
// }

// double getTempAvg(){
//   double sum  = 0;
//   for(int i = 0; i < kNumOfRecords; i++){
//     sum += temp_records[i];
//   }
//   sum /= kNumOfRecords;
//   return sum;
// }

// double getDerivAvg(){
//   double sum  = 0;
//   for(int i = 0; i < kNumOfRecords; i++){
//     sum += deriv_records[i];
//   }
//   sum /= kNumOfRecords;
//   return sum;
// }



// double CalculateDerivative(double currTemp){
//   static unsigned long prevTime = millis();
//   double prevTemp = getAvg();
  
//   unsigned long currTime = millis();
//   unsigned long ElapsedTime = currTime - prevTime;

//   double diffTemp = currTemp - prevTemp;
  
//   double deriv = diffTemp / ElapsedTime;
//   prevTime = currTime;
//   prevTemp = currTemp;

//   addToDerivRingBuffer(deriv)

//   return getDerivAvg();
// }

// void SetFanSpeed(int fan_speed) {
//   if(fan_speed < 10)
//   {
//     analogWrite(kFan, 10);
//   }
//   else
//   {
//     analogWrite(kFan, fan_speed);
//   }
// }

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
