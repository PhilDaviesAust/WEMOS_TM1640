/*
WEMOS_TM1640_LED.cpp - Library implementation for TM1640.
Based on WEMOS_Matrix_LED_Shield_Arduino_library by WEMOS
https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library

Phil Davies 2018-10-27
*/
#include "WEMOS_TM1640.h"

TM1640::TM1640(uint8_t _intensity, uint8_t dataPin, uint8_t clockPin)
{
	this->dataPin  = dataPin;
	this->clockPin = clockPin;

	if(_intensity>7)
		intensity=7;
	else
		intensity=_intensity;

	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	
	digitalWrite(dataPin, HIGH);
	digitalWrite(clockPin, HIGH);

}

void TM1640::display()
{
	for(uint8_t i=0;i<16;i++)
	{
		sendData(i);
	}
	sendCommand(0x88|(intensity));	// display command - set pulse width
}

void TM1640::clear(bool fill)
{
	uint8_t fdat;
	if(fill)
	{
		fdat=0xff;
	}
	else
	{
		fdat=0x00;
	}
	for(uint8_t i=0;i<16;i++)
	{	
		disBuffer[i]= fdat;
	}
	display();
}

void TM1640::dot(uint8_t x, uint8_t y, bool draw)
{
	x&=0x07;		//limit address range to 8
	y&=0x0F;		//limit address range to 16

	if(draw)
	{
		disBuffer[y]|=(1<<x);
	}
	else
	{
		disBuffer[y]&=~(1<<x);
	}
	display();
}

void TM1640::writeCharToBuffer(uint8_t address, uint8_t charnumber)
{
	disBuffer[address]=FONT[charnumber];
}

void TM1640::writeToBuffer(uint8_t address, uint8_t data)
{
	disBuffer[address]=data;
}

void TM1640::sendData(uint8_t address)
{
  sendCommand(0x44);				// data command - fixed address
  digitalWrite(dataPin, LOW);
  send(0xC0 | address);
  send(disBuffer[address]);
  digitalWrite(dataPin, HIGH);
}

void TM1640::sendCommand(uint8_t cmd)
{
  digitalWrite(dataPin, LOW);
  send(cmd);
  digitalWrite(dataPin, HIGH);
}

void TM1640::send(uint8_t data)
{
  for (int i = 0; i < 8; i++) {
    digitalWrite(clockPin, LOW);
    digitalWrite(dataPin, data & 1 ? HIGH : LOW);
    data >>= 1;
    digitalWrite(clockPin, HIGH);
  }
}