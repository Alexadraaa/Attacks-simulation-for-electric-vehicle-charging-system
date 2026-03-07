/*Car simulation for state detection*/

//pins
const int stateDetPin = A0;

const int STATEC_PIN = 5;
const int STATEB_PIN = 6;
const int STATED_PIN = 3;

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

  Serial.begin(9600);
}

void loop(){

  int adcValue = analogRead(stateDetPin);
  float voltage = adcValue * (5.0 / 1023.0);
  Serial.print("  Voltage: ");
  Serial.println(voltage);


  if(adcValue >= STATE_B_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, HIGH);
    digitalWrite(STATED_PIN, LOW);
    Serial.println("State B");

  } else if (adcValue >= STATE_C_MIN) {
    digitalWrite(STATEC_PIN, HIGH);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    Serial.println("State C");

  } /*else if (adcValue = STATE_D_MAX) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, HIGH);
    Serial.println("State D");*/
}