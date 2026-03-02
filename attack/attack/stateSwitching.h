#ifndef stateSwitching_H
#define stateSwitching_H


#include <stdint.h>
#include <math.h>
#include "pins.h"

//intialize state switching
void stateSwitchingInit() {
    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, LOW); // Start with state switching mosfet off
    }

#endif stateSwitching_H