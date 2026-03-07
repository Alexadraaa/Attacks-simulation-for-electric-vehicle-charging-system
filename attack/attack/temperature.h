#ifndef temperature_H
#define temperature_H

#include <stdint.h>
#include <math.h>
#include "pins.h"

#define TEMP_THRESHOLD_HIGH 60.0 // High temperature threshold in Celsius

//for temperature tracking
//float currentTemp = 0.0;
float maxTempRecorded = 0.0;


//Initialize temperature sensor
void tempInit() {
  pinMode(TEMP_PIN, INPUT);
  Serial.println("Temperature sensor initialized");
}

//Read temperature from sensor
float readTemperature() {
  float currentTemp ;
 long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(TEMP_PIN);
    delay(2);
  }
  // Convert the analog reading to voltage
  float voltage = (sum / 10.0) * (5.0 / 1023.0);
  // Convert voltage to temperature in Celsius (assuming a 10mV/°C scale factor)
  float temperatureC = (voltage - 0.5) * 100.0;
  currentTemp = temperatureC;

  // Update max temperature recorded
  if (currentTemp > maxTempRecorded) {
    maxTempRecorded = currentTemp;
  }

  return currentTemp;
}

//check if temperature is safe
bool isTemperatureSafe(float temp) {
  return temp < TEMP_THRESHOLD_HIGH;
}


#endif 