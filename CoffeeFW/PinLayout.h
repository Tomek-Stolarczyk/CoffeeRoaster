#ifndef PINLAYOUT_H
#define PINLAYOUT_H

#include "Arduino.h"

typedef uint8_t Pin_ID;

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
    static const AnalogPin kManualControllerEnable = AnalogPin::A0; 
    static const AnalogPin kManualControllerValue = AnalogPin::A1;
    
    // Fan attached to solid state relay
    static const AnalogPin kFanOutput = AnalogPin::A5;

    // Thermocouple
    static const DigitalPin kThermoSO = DigitalPin::D8;
    static const DigitalPWNPin ktcCS = DigitalPWNPin::D9;
    static const DigitalPWNPin ktcCLK = DigitalPWNPin::D10;
}

#endif