#include "FastLED.h"


////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RGB Calibration code
//
// Use this sketch to determine what the RGB ordering for your chipset should be.  Steps for setting up to use:

// * Uncomment the line in setup that corresponds to the LED chipset that you are using.  (Note that they
//   all explicitly specify the RGB order as RGB)
// * Define DATA_PIN to the pin that data is connected to.
// * (Optional) if using software SPI for chipsets that are SPI based, define CLOCK_PIN to the clock pin
// * Compile/upload/run the sketch 

// You should see six leds on.  If the RGB ordering is correct, you should see 1 red led, 2 green 
// leds, and 3 blue leds.  If you see different colors, the count of each color tells you what the 
// position for that color in the rgb orering should be.  So, for example, if you see 1 Blue, and 2
// Red, and 3 Green leds then the rgb ordering should be BRG (Blue, Red, Green).  

// You can then test this ordering by setting the RGB ordering in the addLeds line below to the new ordering
// and it should come out correctly, 1 red, 2 green, and 3 blue.
//
//////////////////////////////////////////////////

#define NUM_LEDS 16

// Data pin that led data will be written out over
#define DATA_PIN 6
// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);

      // Uncomment one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
       FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() {
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
   delay(50);
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
   delay(50);
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
   delay(50);
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
}
