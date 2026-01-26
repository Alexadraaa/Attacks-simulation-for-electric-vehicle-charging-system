#ifndef temperature_H
#define temperature_H

#include <stdint.h>
#include <math.h>
#include <pins.h>

#define TEMP_THRESHOLD_HIGH 60.0 // High temperature threshold in Celsius

//for temperature tracking
float currentTemp = 0.0;
float maxTempRecorded = 0.0;


//Initialize temperature sensor
void tempInit() {
  pinMode(TEMP_PIN, INPUT);
  Serial.println("Temperature sensor initialized");
}

//Read temperature from sensor
float readTemperature() {
  int sensorValue = analogRead(TEMP_PIN);
  // Convert the analog reading to voltage
  float voltage = sensorValue * (5.0 / 1023.0);
  // Convert voltage to temperature in Celsius (assuming a 10mV/°C scale factor)
  float temperatureC = voltage * 100.0;
  currentTemp = temperatureC;

  // Update max temperature recorded
  if (currentTemp > maxTempRecorded) {
    maxTempRecorded = currentTemp;
  }

  return currentTemp;
}

//check if temperature is safe
bool isTemperatureSafe() {
  return currentTemp < TEMP_THRESHOLD_HIGH;
}


#endif 