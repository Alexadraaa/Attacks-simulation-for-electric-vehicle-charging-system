const int STATE_DET_PIN = A0; // Pin for state detection input
const int PWM_PIN = 10; // PWM output pin for fake load attack
const int FAKELOAD_PIN = 12; // Pin for fake load relay control(M2)

// ADC thresholds (0–1023, scaled to 0–5 V)
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 700;   // ~3.3–4.4 V
const int STATE_C_MIN = 450;   // ~2.1–3.3 V
const int STATE_D_MIN = 200;   // ~0.9–2.1 V
const int STATE_E_MAX = 50;    // ~0 V

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


void setup() {
    fakeLoadInit();
    Serial.begin(9600);
    Serial.println("System Initialized");

}


void loop() {

}

