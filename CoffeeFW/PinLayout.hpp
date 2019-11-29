#ifndef PINLAYOUT_H
#define PINLAYOUT_H

#include <stdint.h>

#include "Arduino.h"

using Pin_ID = uint8_t;

enum class AnalogPin : Pin_ID
{
    A0 = A0,
    A1 = A1,
    A2 = A2,
    A3 = A3,
    A4 = A4,
    A5 = A5
};

enum class DigitalPin : Pin_ID
{
    // 0 RX reserved
    // 1 TX reserved
    D2 = 2,
    // 3 PWM
    D4 = 4, 
    // 5 PWM
    // 6 PWM
    D7 = 7,
    D8 = 8,
    // 9 PWM
    // 10 PWM
    // 11 PWM
    D12 = 12,
    D13 = 13
};

enum class DigitalPWNPin : Pin_ID
{
    D3 = 3,
    D5 = 5,
    D6 = 6,
    D9 = 9,
    D10 = 10,
    D11 = 11
};

namespace Pins
{
    // Manual knob override
    constexpr AnalogPin kManualControllerEnable{ AnalogPin::A0 }; 
    constexpr AnalogPin kManualControllerValue{ AnalogPin::A1 };
    
    // Fan attached to solid state relay
    constexpr AnalogPin kFanOutput{ AnalogPin::A5 };

    // Thermocouple
    constexpr DigitalPin kThermocoupleSO{ DigitalPin::D8 };
    constexpr DigitalPWNPin kThermocoupleCS{ DigitalPWNPin::D9 };
    constexpr DigitalPWNPin kThermocoupleCLK{ DigitalPWNPin::D10 };
}

#endif