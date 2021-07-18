#include "plant.h"
#include "moisture_sensor.h"
#include <Arduino.h>

//Debug toggle
#define DEBUG (1)

static bool plant_initialized(plant_t* plant);

const int minimum_readings_before_actuate = 10;

static bool plant_initialized(plant_t* plant)
{
    if (plant == NULL || !moisture_sensor_initialized(&(plant->sensor)) || !pump_initialized(&(plant->pump)))
    {
        if(DEBUG)
        {
            if(!moisture_sensor_initialized(&(plant->sensor)))
            {
                Serial.println("moisture fail");
            }
            else if(!pump_initialized(&(plant->pump)))
            {
                Serial.println("pump fail");
            }
            else
            {
                Serial.println("null fail");
            }
        }
        return false;
    }
    return true;
}

void plant_init(plant_t* plant, int sensor, int pump)
{
    if (plant == NULL)
    {
        return;
    }

    moisture_sensor_init(&(plant->sensor), sensor);
    pump_init(&(plant->pump), pump);

    plant->on_ticks = 0;
    plant->off_ticks = 0;
    plant->watering_humidity = 30;
    plant->stop_watering_humidity = 70;
}

void check_plant(plant_t* plant)
{    
    if (!plant_initialized(plant))
    {
        return;
    }

    if(DEBUG)
    {
        Serial.print("Sensor: ");
    }

    //get moisture 
    int humidity = moisture_sensor_get_humidity(&(plant->sensor));
    if(DEBUG)
    {
        Serial.print(humidity);
        Serial.print("%");
        Serial.print(" -- ");
    }

    //solve ticks
    if(humidity < plant->watering_humidity)
    {
        plant->off_ticks = 0;
        plant->on_ticks += 1;
    }
    else if(humidity > plant->stop_watering_humidity)
    {
        plant->on_ticks = 0;
        plant->off_ticks += 1;
    }
    else
    {
        plant->on_ticks = 0;
        plant->off_ticks = 0;
    }

    //actuate
    if(plant->on_ticks > minimum_readings_before_actuate)
    {
        pump_on(&(plant->pump));
    }
    if(plant->off_ticks > minimum_readings_before_actuate)
    {
        pump_off(&(plant->pump));
    }

    if(DEBUG)
    {
        Serial.print("on -- ");
        Serial.print(plant->on_ticks);
        Serial.print("  off -- ");
        Serial.print(plant->off_ticks);
        Serial.println();
    }
}

void plant_set_watering_humidity(plant_t* plant, int val)
{
    if (!plant_initialized(plant))
    {
        return;
    }
    plant->watering_humidity = val;
    if(DEBUG)
    {
        Serial.print("Watering humidity set to ");
        Serial.println(plant->watering_humidity);
    }
}

void plant_set_stop_watering_humidity(plant_t* plant, int val)
{
    if (!plant_initialized(plant))
    {
        return;
    }
    plant->stop_watering_humidity = val;
    if(DEBUG)
    {
        Serial.print("Stop wtering humidity set to ");
        Serial.println(plant->stop_watering_humidity);
    }
}
