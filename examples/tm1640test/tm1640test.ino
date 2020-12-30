#include <WEMOS_TM1640.h>

uint8_t brightness = 4;
TM1640 mled(brightness);

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
  
}
///////////////////////////////////////////////////////////
void printBuffer()
{
  Serial.print("buff=");
  for (int i=0; i<16; i++){Serial.printf("%i ", mled.disBuffer[i]);}
  Serial.println("");

}
///////////////////////////////////////////////////////////
void drawCharacter(){
  for(int x=0;x<16;x++)
  {
    mled.writeCharToBuffer(x, x);
    mled.display();
    printBuffer();
    delay(500);
  }
  delay(500);  
  mled.clear();    
}
//////////////////////////////////////////////////////////
void drawDot(){
    for(int y=0;y<8;y++)
  {
    for(int x=0;x<8;x++)
    {
      mled.dot(x,y); // draw dot
      printBuffer();
      delay(500);
    mled.clear();
    }
    delay(500);  
  }
}
//////////////////////////////////////////////////////////
void useClear(){
  mled.clear(true);   // fill buffer
  printBuffer();
  delay(500);
  mled.clear(false);  //clear buffer
  printBuffer();
}
/////////////////////////////////////////////////////////
void loop() {
  //drawCharacter();
  //useClear();
  drawDot();
  delay(500);
}
