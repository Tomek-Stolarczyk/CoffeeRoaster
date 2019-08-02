#include "Thermocouple.h"


template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
Thermocouple::Thermocouple() :
    sensor(static_cast<uint8_t>(CLK), static_cast<uint8_t>(CS), static_cast<uint8_t>(SO))
{

}

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
void Thermocouple::Update()
{
    tempurature = sensor.readCelsius();
}

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
const double Thermocouple::GetTempurature() const
{
    return tempurature;
}
