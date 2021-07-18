#pragma once
#include "moisture_sensor.h"
#include "pump.h"

typedef struct plant
{
  moisture_sensor_t sensor;
  pump_t pump;
  int on_ticks;
  int off_ticks;
  int watering_humidity;
  int stop_watering_humidity;
} plant_t;

void plant_init(plant_t* plant, int sensor, int pump);

void check_plant(plant_t* plant);

void plant_set_watering_humidity(plant_t* plant, int val);

void plant_set_stop_watering_humidity(plant_t* plant, int val);
