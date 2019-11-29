#ifndef THERMOCOUPLE_H
#define THERMOCOUPLE_H

#include <max6675.h>

#include "PinLayout.hpp"
#include "Updateable.hpp"

Updateable* CreateThermocouple();

template<DigitalPin so, DigitalPWNPin cs, DigitalPWNPin clk>
class Thermocouple : public Updateable
{
  public:
    Thermocouple();
    double const GetTempurature() const;
    void Update() noexcept override;

  private:
    MAX6675 m_sensor;
    double m_tempurature{ 0 };
};

#endif