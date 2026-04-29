/*Car simulation for state detection*/

//pins
const int stateDetPin = A0;

const int STATEC_PIN = 13;
const int STATEB_PIN = 12;
const int STATED_PIN = 7;
const int LED_C = 11;
const int LED_B = 10;
const int LED_D = 9;


//values for thesholds
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 675;   // ~3.3–4.4 V
const int STATE_C_MIN = 430;   // ~2.1–3.3 V
const int STATE_D_MIN = 200;   // ~0.9–2.1 V
const int STATE_F_MIN = 11;   // ~0.05–0.98 V
const int STATE_E_MAX = 50;    // ~0 V


void setup() {

  pinMode(stateDetPin, INPUT);
  
  pinMode(STATEC_PIN, OUTPUT);
  pinMode(STATEB_PIN, OUTPUT);
  pinMode(STATED_PIN, OUTPUT);
  digitalWrite(STATEC_PIN, LOW);
  digitalWrite(STATEB_PIN, LOW);
  digitalWrite(STATED_PIN, LOW);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_D, OUTPUT);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
  delay(400);

  Serial.begin(9600);
}

void loop(){

  analogRead(stateDetPin);  // discard first reading
delay(10); 
  int adcValue = analogRead(stateDetPin);
  float voltage = adcValue * (5.0 / 1023.0);
  Serial.print("  Voltage: ");
  Serial.println(voltage);
  
  if (adcValue >= STATE_A_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
    Serial.println("State A");
}
  else if(adcValue >= STATE_B_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, HIGH);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, HIGH);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW); 
    Serial.println("State B");
    

  } else if (adcValue >= STATE_C_MIN) {
    digitalWrite(STATEC_PIN, HIGH);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, HIGH);
    digitalWrite(LED_D, LOW);
    Serial.println("State C");
   
    

  } 
  else if (adcValue >= STATE_D_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, HIGH);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, HIGH);
    Serial.println("State D");
  }
  
    else if (adcValue >= STATE_F_MIN) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
    Serial.println("State F");
  }
  
  else if (adcValue <= STATE_E_MAX) {
    digitalWrite(STATEC_PIN, LOW);
    digitalWrite(STATEB_PIN, LOW);
    digitalWrite(STATED_PIN, LOW);
    digitalWrite(LED_B, LOW);
    digitalWrite(LED_C, LOW);
    digitalWrite(LED_D, LOW);
    Serial.println("State E");
    
  }
  
  Serial.print("State C PIN state: ");
  Serial.println(digitalRead(STATEC_PIN)); //print stateC pin state
  
  Serial.print("State B PIN state: ");
  Serial.println(digitalRead(STATEB_PIN)); //print stateB pin state
 
  Serial.print("State D PIN state: "); 
  Serial.println(digitalRead(STATED_PIN)); //print stateD pin staten state
   
  delay(100);
}