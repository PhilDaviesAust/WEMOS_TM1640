#include <WEMOS_TM1640.h>

TM1640 mled(5); //set intensity=5

void setup() {
  // put your setup code here, to run once:

  
}

void loop() {

  for(int y=0;y<8;y++)
  {
    for(int x=0;x<8;x++)
    {
        mled.dot(x,y,true); 	// draw dot
        delay(200);
        mled.dot(x,y,false);	// clear dot
        delay(200);        
    }  
  }

}
