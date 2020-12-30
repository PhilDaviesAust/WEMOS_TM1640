#include <WEMOS_TM1640.h>

TM1640 mled(0); //set intensity=0

void setup() {
  Serial.begin(115200);
  mled.clear(true);		// fill screen
}

void loop() {

  for(int i=0;i<8;i++){
    mled.intensity=i;	//change intensity
    mled.display();
    delay(1000);
  }
}
