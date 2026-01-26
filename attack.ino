/*attack circuit*/

#include <temperature.h>
#include <fakeLoad.h>
#include <stateSwitching.h>


void setup() {
pinMode(REALLOAD_PIN, OUTPUT);
fakeLoadInit();
tempInit();
stateSwitchingInit();

 Serial.begin(9600);

}

void loop() {


}
