const int STATE_DET_PIN = A0; // Pin for state detection input
const int PWM_PIN = 9; // PWM output pin for fake load attack
//const int FAKELOAD_PIN = 12; // Pin for fake load relay control(M2)

// ADC thresholds (0–1023, scaled to 0–5 V)
//values for thesholds
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 675;   // ~3.3–4.4 V
const int STATE_C_MIN = 430;   // ~2.1–3.3 V
const int STATE_D_MIN = 200;   // ~0.9–2.1 V
const int STATE_E_MAX = 50;    // ~0 V

// duty cycles
#define NORMAL_DUTY  128  // 2.49V - normal State C (26.5% → 16A equivalent)
#define REDUCED_DUTY 115  // 2.10V - reduced State C (10% → 6A equivalent)

//intialize fake load attack
/*void fakeLoadInit() {
    pinMode(FAKELOAD_PIN, OUTPUT);
    pinMode(PWM_PIN, OUTPUT);

    digitalWrite(FAKELOAD_PIN, LOW); // Start with fake load mosfet off
    digitalWrite(PWM_PIN, LOW); // Start with PWM off
    }    

void fakeloadEN(uint8_t dutyCycle) {
  
    analogWrite(PWM_PIN, dutyCycle); // Set PWM duty cycle
    digitalWrite(FAKELOAD_PIN, HIGH); // Enable fake load mosfet
   
}

void fakeloadDIS() {
    analogWrite(PWM_PIN, LOW);
    digitalWrite(FAKELOAD_PIN, LOW);
}

//StateC detector
bool isStateC() {
    int adcValue = analogRead(STATE_DET_PIN);
  Serial.print("ADC Value: ");
  Serial.println(adcValue);
    return (adcValue >= STATE_C_MIN && adcValue < STATE_B_MIN);
}
*/
void setup() {
    pinMode(STATE_DET_PIN, INPUT);
    //fakeLoadInit();
  pinMode(PWM_PIN,OUTPUT);
    Serial.begin(9600);
    Serial.println("System Initialized");

}


void loop() {
        /*if (!isStateC()) {
        Serial.println("Not State C - attack inactive");
        fakeloadDIS();
        delay(500);
        return;
    }
fakeloadEN(128);

    Serial.print("FAKELOAD PIN: "); 
    Serial.println(digitalRead(FAKELOAD_PIN));
    Serial.print("PWM PIN: "); 
    Serial.println(digitalRead(PWM_PIN));
    Serial.print("Duty cycle: "); 
    Serial.println(REDUCED_DUTY);

    delay(100);*/
  
  /*for(int value=0; value<=255; value++){
  analogWrite(PWM_PIN,value);
    delay(50);
  }
  
    for(int value=255; value<=0; value--){
  analogWrite(PWM_PIN,value);
    delay(50);
  }*/
  
  analogWrite(PWM_PIN,107);
}

