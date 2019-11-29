#include "Thermocouple.hpp"

Updateable* CreateThermocouple()
{
  return new Thermocouple<Pins::kThermocoupleSO,
                          Pins::kThermocoupleCS,
                          Pins::kThermocoupleCLK>();
}

template<DigitalPin SO, DigitalPWNPin CS, DigitalPWNPin CLK>
Thermocouple<SO, CS, CLK>::Thermocouple() : 
    m_sensor(static_cast<uint8_t>(CLK), 
             static_cast<uint8_t>(CS), 
             static_cast<uint8_t>(SO))
{
}

template<DigitalPin SO, DigitalPWNPin CS, DigitalPWNPin CLK>
void Thermocouple<SO, CS, CLK>::Update()
{
    m_tempurature = m_sensor.readCelsius();
}

template<DigitalPin SO, DigitalPWNPin CS, DigitalPWNPin CLK>
double const Thermocouple<SO, CS, CLK>::GetTempurature() const
{
    return m_tempurature;
}
