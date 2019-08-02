#include "Thermocouple.h"


template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
Thermocouple<SO, CS, CLK>::Thermocouple() : 
    sensor(static_cast<uint8_t>(CLK), static_cast<uint8_t>(CS), static_cast<uint8_t>(SO))
{

}

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
void Thermocouple<SO, CS, CLK>::Update()
{
    tempurature = sensor.readCelsius();
    dtostrf(tempurature, 4, 4, tempurature_s);
}

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
const double Thermocouple<SO, CS, CLK>::GetTempurature() const
{
    return tempurature;
}

template<const DigitalPin SO, const DigitalPWNPin CS, const DigitalPWNPin CLK>
const char* Thermocouple<SO, CS, CLK>::GetTempurature_s() const
{
    return tempurature_s;
}
