#ifndef PINS_H
#define PINS_H

#include <stdint.h>

const int STATE_DET_PIN = A0; // Pin for state detection input

const int TEMP_PIN = A1; // Pin for temperature sensor

const int PWM_PIN = 10; // PWM output pin for fake load attack

//Mosfets
const int FAKELOAD_PIN = 6; // Pin for fake load mosfet control(M2)
const int REALLOAD_PIN = 5; // Pin for real load mosfet control(M1)
const int SS_PIN = 3; // Pin for state switching mosfet control(M3)



#endif

