#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include "PinLayout.h"
#include "Updateable.h"

#include <max6675.h>

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
class Thermocouple : public Updateable
{
  public:
    Thermocouple();
    const double GetTempurature() const;
    const char* GetTempurature_s() const;
    void Update() override;

  private:
    MAX6675 sensor;
    double tempurature = 0;
    char tempurature_s[7];
};

#endif