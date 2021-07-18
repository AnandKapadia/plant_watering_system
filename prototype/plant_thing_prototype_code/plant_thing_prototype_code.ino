#include "plant.h"
#include "moisture_sensor.h"
#include "pump.h"

//Pin Maps
int pump_1 = 2;
int moisture_sensor_1 = A0;

//Humidity Levels
const int pump_on_humidity  = 30;
const int pump_off_humidity = 70;

plant_t plant_1; 

void setup() {

  Serial.begin(9600);

  //Plant 1
  plant_init(&plant_1, moisture_sensor_1, pump_1);
  moisture_sensor_set_dry_reading(&(plant_1.sensor), 495);
  moisture_sensor_set_wet_reading(&(plant_1.sensor), 320);
  plant_set_watering_humidity(&plant_1, 30);
  plant_set_stop_watering_humidity(&plant_1, 70);
  Serial.println("Sensor1 initialized");
  
  //Plant i...
}

void loop() {
  check_plant(&plant_1);
  delay(500);
}   
