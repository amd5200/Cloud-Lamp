// Uncomment this line if you have any interrupts that are changing pins - this causes the library to be a little bit more cautious
// #define FAST_SPI_INTERRUPTS_WRITE_PINS 1

// Uncomment this line to force always using software, instead of hardware, SPI (why?)
// #define FORCE_SOFTWARE_SPI 1

// Uncomment this line if you want to talk to DMX controllers
// #define FASTSPI_USE_DMX_SIMPLE 1

#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// test code
//
//////////////////////////////////////////////////

// How many leds are in the strip?
#define NUM_LEDS 16

// Data pin that led data will be written out over
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);

   	// For safety (to prevent too high of a power draw), the test case defaults to
   	// setting brightness to 25% brightness
   	LEDS.setBrightness(64);
        //LEDS.setBrightness(84);

        LEDS.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
   	// LEDS.addLeds<WS2811, 13>(leds, NUM_LEDS);
   	// LEDS.addLeds<TM1809, 13>(leds, NUM_LEDS);
   	// LEDS.addLeds<UCS1903, 13>(leds, NUM_LEDS);
   	// LEDS.addLeds<TM1803, 13>(leds, NUM_LEDS);

   	// LEDS.addLeds<P9813>(leds, NUM_LEDS);
 // 	CLEDController *pLed = new ClocklessController_Trinket<4, NS(400), NS(400), NS(450), GRB>();
 //  	LEDS.addLeds(pLed, leds, NUM_LEDS);
   	// LEDS.addLeds<LPD8806>(leds, NUM_LEDS);
	// LEDS.addLeds<WS2801>(leds, NUM_LEDS);
   	// LEDS.addLeds<SM16716>(leds, NUM_LEDS);

   	// LEDS.addLeds<WS2811, 11>(leds, NUM_LEDS);

	// Put ws2801 strip on the hardware SPI pins with a BGR ordering of rgb and limited to a 1Mhz data rate
	// LEDS.addLeds<WS2801, 11, 13, BGR, DATA_RATE_MHZ(1)>(leds, NUM_LEDS);

   	// LEDS.addLeds<LPD8806, 10, 11>(leds, NUM_LEDS);
   	// LEDS.addLeds<WS2811, 13, BRG>(leds, NUM_LEDS);
   	// LEDS.addLeds<LPD8806, BGR>(leds, NUM_LEDS);
}

void loop() { 
	for(int i = 0; i < 3; i++) {
		for(int iLed = 0; iLed < NUM_LEDS; iLed++) {
			memset(leds, 0,  NUM_LEDS * sizeof(struct CRGB));

			switch(i) { 
				// You can access the rgb values by field r, g, b
			 	case 0: leds[iLed].r = 128; break;

			 	// or by indexing into the led (r==0, g==1, b==2) 
			 	case 1: leds[iLed][i] = 128; break;

			 	// or by setting the rgb values for the pixel all at once
			 	case 2: leds[iLed] = CRGB(0, 0, 128); break;
			}

			// and now, show your led array! 
			LEDS.show();
			delay(50);
		}
    //  white		
   leds[0] = CRGB::Red; 
   leds[1] = CRGB::Green;
   leds[2] = CRGB::Green;
   leds[3] = CRGB::White;
   leds[4] = CRGB::Blue;
   leds[5] = CRGB::Blue;
   leds[6] = CRGB::White;
   leds[7] = CRGB::Blue;
   leds[8] = CRGB::Blue;
   leds[9] = CRGB::White;
   leds[10] = CRGB::Blue;
   leds[11] = CRGB::Blue;
   leds[12] = CRGB::White;
   leds[13] = CRGB::Blue;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(500);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(500);
   leds[0] = CRGB::Red; 
   leds[1] = CRGB::Green;
   leds[2] = CRGB::Green;
   leds[3] = CRGB::White;
   leds[4] = CRGB::Blue;
   leds[5] = CRGB::Blue;
   leds[6] = CRGB::White;
   leds[7] = CRGB::Blue;
   leds[8] = CRGB::Blue;
   leds[9] = CRGB::White;
   leds[10] = CRGB::Blue;
   leds[11] = CRGB::Blue;
   leds[12] = CRGB::White;
   leds[13] = CRGB::Blue;
   leds[14] = CRGB::White;
   leds[15] = CRGB::White;
   FastLED.show();
   delay(500);
   leds[0] = CRGB::Black; 
   leds[1] = CRGB::Black;
   leds[2] = CRGB::Black;
   leds[3] = CRGB::Black;
   leds[4] = CRGB::Black;
   leds[5] = CRGB::Black;
   leds[6] = CRGB::Black;
   leds[7] = CRGB::Black;
   leds[8] = CRGB::Black;
   leds[9] = CRGB::Black;
   leds[10] = CRGB::Black;
   leds[11] = CRGB::Black;
   leds[12] = CRGB::Black;
   leds[13] = CRGB::Black;
   leds[14] = CRGB::Black;
   leds[15] = CRGB::Black;
   FastLED.show();
   delay(500);

		// yellow	
	       LEDS.showColor(CRGB(128, 128, 0));                        
	       delay(500);

		//fade  up
		for(int x = 0; x < 128; x++) { 
			// The showColor method sets all the leds in the strip to the same color
			LEDS.showColor(CRGB(x, 0, 0));
                        
			delay(10);
		}

		// fade down
		for(int x = 128; x >= 0; x--) { 
			LEDS.showColor(CRGB(x, 0, 0));
                        
			delay(10);
		}

		// let's fade up by scaling the brightness
		for(int scale = 0; scale < 128; scale++) { 
			LEDS.showColor(CRGB(0, 128, 0), scale);
			delay(10);
		}

		// let's fade down by scaling the brightness
		for(int scale = 128; scale > 0; scale--) { 
			LEDS.showColor(CRGB(0, 128, 0), scale);
			delay(10);
		}
		
	}
        
}