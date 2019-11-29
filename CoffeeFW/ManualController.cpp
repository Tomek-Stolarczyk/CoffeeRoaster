#include "ManualController.hpp"

Updateable* CreateManualController()
{
  return new ManualController<Pins::kManualControllerEnable,
                              Pins::kManualControllerValue>();
}

template<AnalogPin enable, AnalogPin value>
bool const ManualController<enable, value>::IsOverrideEnabled() const
{
  return m_enabled;
}

template<AnalogPin enable, AnalogPin value>
uint32_t const ManualController<enable,value>::GetOverrideValue() const
{
  return m_value;
}

template<AnalogPin enable, AnalogPin value>
void ManualController<enable,value>::Update()
{
  m_enabled = analogRead(static_cast<uint8_t>(enable));
  m_value = analogRead(static_cast<uint8_t>(value));
}
