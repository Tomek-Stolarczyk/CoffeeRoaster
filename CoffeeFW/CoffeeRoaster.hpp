#ifndef COFFEEROASTER_H
#define COFFEEROASTER_H

#include <stdint.h>

#include "Updateable.hpp"

enum UpdatableComponents : uint8_t 
{
    MANUAL_CONTROLLER = 0,
    //AUTOMATED_CONTROLLER,
    THERMOCOUPLE,
    TOTAL_UPDATEABLE
};

class CoffeeRoaster final
{
  public:
    void setup();
    void loop();

  private:
    Updateable* m_components[TOTAL_UPDATEABLE];
};

#endif
