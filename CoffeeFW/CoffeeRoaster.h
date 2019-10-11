#ifndef COFFEEROASTER_H
#define COFFEEROASTER_H

#include "Updateable.h"
#include "Thermocouple.h"
#include "ManualController.h"

class CoffeeRoaster
{
  public:
    CoffeeRoaster() = default;
  
    void setup();
    void loop();

  private:
    //Updateable components[2] = {Thermocouple(), ManualController()};
};

#endif