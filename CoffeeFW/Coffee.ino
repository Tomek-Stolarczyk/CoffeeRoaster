#include "CoffeeRoaster.hpp"

CoffeeRoaster Roaster;

void setup() {
  Serial.begin(19200);
  Roaster.setup();
}

void loop() {
  Roaster.loop();
}
