#include "moisture_sensor.h"
#include <Arduino.h>


//Debug toggle
#define DEBUG (1)


bool moisture_sensor_initialized(moisture_sensor_t* sensor)
{
    if (sensor == NULL)
    {
        return false;
    }
    return true;
}

void moisture_sensor_init(moisture_sensor_t* sensor, int pin)
{
    if(sensor == NULL)
    {
        return;
    }
    sensor->pin = pin;
    sensor->calibrated_dry_reading = 550;
    sensor->calibrated_wet_reading = 150;
    sensor->humidity = 1000;
}

void moisture_sensor_set_dry_calibration(moisture_sensor_t* sensor, int dry)
{
    if(!moisture_sensor_initialized(sensor))
    {
        return;
    }
    sensor->calibrated_dry_reading = dry;
    if(DEBUG)
    {
        Serial.print("Dry Calibration set to ");
        Serial.println(sensor->calibrated_dry_reading);
    }
}

void moisture_sensor_set_wet_calibration(moisture_sensor_t* sensor, int wet)
{
    if(!moisture_sensor_initialized(sensor))
    {
        return;
    }
    sensor->calibrated_wet_reading = wet;
    if(DEBUG)
    {
        Serial.print("Wet Calibration set to ");
        Serial.println(sensor->calibrated_wet_reading);
    }
}

int moisture_sensor_get_humidity(moisture_sensor_t* sensor)
{
    if(!moisture_sensor_initialized(sensor))
    {
        return 1000;
    }
    int raw_value = analogRead(sensor->pin);
    if(DEBUG)
    {
        Serial.print("raw: ");
        Serial.print(raw_value);
        Serial.print("--");
    }
    sensor->humidity = map(raw_value, sensor->calibrated_wet_reading, sensor->calibrated_dry_reading, 100, 0);
    return sensor->humidity;
}
