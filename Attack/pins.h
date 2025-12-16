#ifndef PINS_H
#define PINS_H

#include <stdint.h>

#define STATE_DET_PIN A2 // Pin for state detection input

#define TEMP_PIN A1 // Pin for temperature sensor

#define PWM_PIN 10 // PWM output pin for fake load attack

//Mosfets
#define FAKELOAD_PIN 6 // Pin for fake load mosfet control(M2)
#define REALLOAD_PIN 5 // Pin for real load mosfet control(M1)
#define SS_PIN 3 // Pin for state switching mosfet control(M3)



#endif
