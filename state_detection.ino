/*Charger Simulation*/

//pins
const int pilotPin = A0;

const int RED_PIN   = 11;
const int GREEN_PIN = 9;
const int BLUE_PIN  = 10;

//values for thesholds
const int STATE_A_MIN = 900;   // ~4.4–5.0 V
const int STATE_B_MIN = 700;   // ~3.3–4.4 V
const int STATE_C_MIN = 450;   // ~2.1–3.3 V
const int STATE_E_MAX = 50;    // ~0 V

void setup() {

  pinMode(pilotPin, INPUT);
  
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  Serial.begin(9600);
}


void loop(){
    
  int adcValue = analogRead(pilotPin);
  float voltage = adcValue * (5.0 / 1023.0);
  Serial.print("  Voltage: ");
  Serial.println(voltage);

  if (adcValue >= STATE_A_MIN) {
    setColor(255, 120, 0); //stateA : orange
    Serial.println("State A");

  } else if (adcValue >= STATE_B_MIN) {
    setColor(0, 0, 255); //stateB : blue
    Serial.println("State B");

  } else if (adcValue >= STATE_C_MIN) {
    setColor(0, 255, 0); //stateC : green
    Serial.println("State C");

  } else if (adcValue <= STATE_E_MAX) {
    setColor(0, 0, 0); //stateE : off
    Serial.println("State E");

  } else {
    setColor(255, 0, 0); //stateF : red 
    Serial.println("State F");
  }



}


//helper function for color of rgb led
void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}