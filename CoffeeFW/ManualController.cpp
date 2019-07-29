#include "ManualController.h"

template<const AnalogPin a, const AnalogPin b>
const bool ManualController<a,b>::IsOverrideEnabled() const
{
  return enabled;
}

template<const AnalogPin a, const AnalogPin b>
const unsigned int ManualController<a,b>::GetOverrideValue() const
{
  return value;
}

template<const AnalogPin EnablePin, const AnalogPin ValuePin>
void ManualController<EnablePin,ValuePin>::Update()
{
  enabled = analogRead(static_cast<uint8_t>(EnablePin));
  value = analogRead(static_cast<uint8_t>(ValuePin));
}
