#include "plant.h"
#include "moisture_sensor.h"
#include "pump.h"

#define ANAND (0)
#define BRYDEN (1)

#if ANAND
plant_t plant_1; 
#endif

#if BRYDEN
plant_t plant_1; 
plant_t plant_2; 
plant_t plant_3; 
plant_t plant_4; 
#endif

void setup() {

  Serial.begin(9600);
#if ANAND
  //Plant 1
  plant_init(&plant_1, 2, A0);
  moisture_sensor_set_dry_calibration(&(plant_1.sensor), 495);
  moisture_sensor_set_wet_calibration(&(plant_1.sensor), 320);
  plant_set_watering_humidity(&plant_1, 30);
  plant_set_stop_watering_humidity(&plant_1, 70);
  Serial.println("Sensor1 initialized");
#endif 

#if BRYDEN
  //Plant 1
  plant_init(&plant_1, A0, 8);
  moisture_sensor_set_dry_calibration(&(plant_1.sensor), 600);
  moisture_sensor_set_wet_calibration(&(plant_1.sensor), 100);
  plant_set_watering_humidity(&plant_1, 30);
  plant_set_stop_watering_humidity(&plant_1, 70);
  Serial.println("Sensor1 initialized");
  
  //Plant 2
  plant_init(&plant_2, A1, 9);
  moisture_sensor_set_dry_calibration(&(plant_2.sensor), 600);
  moisture_sensor_set_wet_calibration(&(plant_2.sensor), 100);
  plant_set_watering_humidity(&plant_2, 30);
  plant_set_stop_watering_humidity(&plant_2, 70);
  Serial.println("Sensor2 initialized");

  //Plant 3
  plant_init(&plant_3, A2, 10);
  moisture_sensor_set_dry_calibration(&(plant_3.sensor), 600);
  moisture_sensor_set_wet_calibration(&(plant_3.sensor), 100);
  plant_set_watering_humidity(&plant_3, 30);
  plant_set_stop_watering_humidity(&plant_3, 70);
  Serial.println("Sensor3 initialized");

  //Plant 4
  plant_init(&plant_4, A3, 11);
  moisture_sensor_set_dry_calibration(&(plant_4.sensor), 600);
  moisture_sensor_set_wet_calibration(&(plant_4.sensor), 100);
  plant_set_watering_humidity(&plant_4, 30);
  plant_set_stop_watering_humidity(&plant_4, 70);
  Serial.println("Sensor4 initialized");
#endif
}

void loop() {
#if ANAND
  check_plant(&plant_1);
#endif
#if BRYDEN
  check_plant(&plant_1);
  check_plant(&plant_2);
  check_plant(&plant_3);
  check_plant(&plant_4);
#endif
  Serial.println("--------");
  delay(500);
}   
