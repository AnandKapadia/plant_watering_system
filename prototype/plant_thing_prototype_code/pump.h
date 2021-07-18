#pragma once

typedef struct pump
{
    int pin;
    int state;
} pump_t;

bool pump_initialized(pump_t* pump);
void pump_init(pump_t* pump, int pin);
void pump_on(pump_t* pump);
void pump_off(pump_t* pump);
