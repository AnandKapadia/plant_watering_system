#include "pump.h"
#include <Arduino.h>

bool pump_initialized(pump_t* pump)
{
    if(pump == NULL)
    {
        return false;
    }
    return true;
}

void pump_init(pump_t* pump, int pin)
{
    if(pump == NULL)
    {
        return;
    }

    pump->pin = pin;
    
    pinMode(pin, OUTPUT);
    pump_off(pump);
}

void pump_on(pump_t* pump)
{
    if(!pump_initialized(pump))
    {
        return;
    }
    pump->state = LOW;
    digitalWrite(pump->pin, LOW);
}

void pump_off(pump_t* pump)
{
    if(!pump_initialized(pump))
    {
        return;
    }
    pump->state = HIGH;
    digitalWrite(pump->pin, HIGH);
}

