/*attack circuit*/

#include <temperature.h>
#include <fakeLoad.h>
#include <stateSwitching.h>

// ADC thresholds (0–1023, scaled to 0–5 V)
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 700;   // ~3.3–4.4 V
const int STATE_C_MIN = 450;   // ~2.1–3.3 V
const int STATE_E_MAX = 50;    // ~0 V

//timing constants (in milliseconds)
#define REALLOAD_TIME_MS       20      // ~1 PWM period
#define FAKELOAD_TIME_MS       3000
#define SS_TIME_MS             2000
#define COOLDOWN_TIME_MS       1000

uint8_t attackTimer = 0;

void setup() {

pinMode(STATE_DET_PIN, INPUT);  
pinMode(REALLOAD_PIN, OUTPUT);
fakeLoadInit();
tempInit();
stateSwitchingInit();

 Serial.begin(9600);

}

//StateC detector
bool isStateC() {
    int adcValue = analogRead(STATE_DET_PIN);
    return (adcValue >= STATE_C_MIN && adcValue < STATE_B_MIN);
}

//Helper functions 

// Only real EV load connected
void realLoadOnly() {
  digitalWrite(REALLOAD_PIN, HIGH);   // M1 ON
  digitalWrite(FAKELOAD_PIN, LOW);   // M2 OFF
  digitalWrite(SS_PIN, LOW);        // M3 OFF
}

// Fake load attack
void fakeLoadOnly(uint8_t dutyCycle) {
  digitalWrite(REALLOAD_PIN, LOW);    // M1 OFF
  digitalWrite(SS_PIN, LOW);        // M3 OFF
  fakeloadEN(dutyCycle);            // Enables fake load MOSFET (M2) and sets PWM
}

// State switching attack
void stateSwitchingLoad() {
  digitalWrite(REALLOAD_PIN, HIGH);   // M1 ON
  digitalWrite(FAKELOAD_PIN, LOW);    // M2 OFF
  digitalWrite(SS_PIN, HIGH);// M3 ON
}


void loop() {
realLoadOnly(); 

}
