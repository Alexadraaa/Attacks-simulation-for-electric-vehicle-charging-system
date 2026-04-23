#ifndef PINS_H
#define PINS_H

#include <stdint.h>

const int STATE_DET_PIN = A0; // Pin for state detection input

const int TEMP_PIN = A1; // Pin for temperature sensor

const int PWM_PIN = 10; // PWM output pin for fake load attack

//relays
const int FAKELOAD_PIN = 12; // Pin for fake load relay control(M2)
const int REALLOAD_PIN = 13; // Pin for real load relay control(M1)
const int SS_PIN = 7; // Pin for state switching relay control(M3)



#endif
