#ifndef fakeLoad_H
#define fakeLoad_H

#include <stdint.h>
#include <math.h>
#include <pins.h>

//intialize fake load attack
void fakeLoadInit() {
    pinMode(FAKELOAD_PIN, OUTPUT);
    pinMode(PWM_PIN, OUTPUT);
    digitalWrite(FAKELOAD_PIN, LOW); // Start with fake load mosfet off
    digitalWrite(PWM_PIN, LOW); // Start with PWM off
    }    

#endif fakeLoad_H