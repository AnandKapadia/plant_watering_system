#pragma once

typedef struct moisture_sensor
{
    int pin;
    int calibrated_dry_reading;
    int calibrated_wet_reading;
    int humidity;
} moisture_sensor_t;


bool moisture_sensor_initialized(moisture_sensor_t* sensor);
void moisture_sensor_init(moisture_sensor_t* sensor, int pin);
void moisture_sensor_set_dry_reading(moisture_sensor_t* sensor, int dry);
void moisture_sensor_set_wet_reading(moisture_sensor_t* sensor, int wet);
int moisture_sensor_get_humidity(moisture_sensor_t* sensor);


