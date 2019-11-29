#include "CoffeeRoaster.hpp"
#include "PinLayout.hpp"
#include "Thermocouple.hpp"
#include "ManualController.hpp"

void CoffeeRoaster::setup()
{
    m_components[MANUAL_CONTROLLER] = CreateManualController();
    m_components[THERMOCOUPLE] = CreateThermocouple();
}

void CoffeeRoaster::loop()
{
}
