/*
WEMOS_TM1640_LED.h - Library implementation for TM1640.
Based on WEMOS_Matrix_LED_Shield_Arduino_library by WEMOS
https://github.com/wemos/WEMOS_Matrix_LED_Shield_Arduino_Library

Phil Davies 2018-10-27
*/

#ifndef __WEMOS_TM1640_H
#define __WEMOS_TM1640_H

#if ARDUINO >= 100
 #include "Arduino.h"
//#else
// #include "WProgram.h"
#endif

#include "WEMOS_TM1640_FONT.h"

class TM1640
{
	public:
		TM1640(uint8_t _intensity=4, uint8_t dataPin=13, uint8_t clockPin=14);
		void display();
		void clear(bool fill=false);
		void dot(uint8_t x, uint8_t y, bool draw=true);
		void writeCharToBuffer(uint8_t position=0, uint8_t charnumber=0);
		void writeToBuffer(uint8_t address, uint8_t data);
		
	    volatile uint8_t disBuffer[16]={
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
			0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
		
	    uint8_t intensity;
		
	protected:
		void sendCommand(uint8_t led);
	    void sendData(uint8_t address);
	    void send(uint8_t data);

	    uint8_t dataPin;
	    uint8_t clockPin;
};

#endif

