/*Car simulation for state detection*/

//pins
const int stateDetPin = A0;

const int STATEC_PIN = 5;
const int STATEB_PIN = 6;
const int STATED_PIN = 3;
const int LED_C = 11;
const int LED_B = 10;
const int LED_D = 9;


//values for thesholds
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 700;   // ~3.3–4.4 V
const int STATE_C_MIN = 450;   // ~2.1–3.3 V
const int STATE_E_MAX = 50;    // ~0 V

void setup() {

  pinMode(stateDetPin, INPUT);
  
  pinMode(STATEC_PIN, OUTPUT);
  pinMode(STATEB_PIN, OUTPUT);
  pinMode(STATED_PIN, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_B, OUTPUT);
  //pinMode(LED_D, OUTPUT);

  Serial.begin(9600);
}

void loop(){

    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    //digitalWrite(LED_D, LOW);

  int adcValue = analogRead(stateDetPin);
  float voltage = adcValue * (5.0 / 1023.0);
  Serial.print("  Voltage: ");
  Serial.println(voltage);

  if (adcValue >= STATE_A_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    //digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    //digitalWrite(LED_D, LOW);
    Serial.println("State A");
}
  else if(adcValue >= STATE_B_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, HIGH);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, HIGH);
    Serial.println("State B");

  } else if (adcValue >= STATE_C_MIN) {
    digitalWrite(STATEC_PIN, HIGH);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_C, HIGH);
    Serial.println("State C");

  } 
  else if (adcValue <= STATE_E_MAX) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    //digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    //digitalWrite(LED_D, LOW);
    Serial.println("State E");
    
  }
  else {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    //digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    //digitalWrite(LED_D, LOW);
    Serial.println("State F");
  }
    /*else if (adcValue = STATE_D_MAX) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, HIGH);
    digitalWrite(LED_D, HIGH);
    Serial.println("State D");*/
    delay(500);
}