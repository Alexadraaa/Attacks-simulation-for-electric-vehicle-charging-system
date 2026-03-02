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

void fakeloadEN(uint8_t dutyCycle) {
    analogWrite(PWM_PIN, dutyCycle); // Set PWM duty cycle
    digitalWrite(FAKELOAD_PIN, HIGH); // Enable fake load mosfet
   
}

#endif 