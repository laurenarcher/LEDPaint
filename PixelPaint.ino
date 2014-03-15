#include <chipsets.h>
#include <clockless.h>
#include <clockless_trinket.h>
#include <controller.h>
#include <delay.h>
#include <dmx.h>
#include <FastLED.h>
#include <fastpin.h>
#include <fastspi.h>
#include <fastspi_arm.h>
#include <fastspi_avr.h>
#include <fastspi_bitbang.h>
#include <fastspi_dma.h>
#include <FastSPI_LED2.h>
#include <hsv2rgb.h>
#include <lib8tion.h>
#include <pixeltypes.h>

// #define FORCE_SOFTWARE_SPI
// #define FORCE_SOFTWARE_PINS

///////////////////////////////////////////////////////////////////////////////////////////
//

// How many leds are in the strip?
#define NUM_LEDS 144

// Data pin that led data will be written out over
#define DATA_PIN 7

// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];

// This function sets up the leds and tells the controller about them
void setup() {
  // sanity check delay - allows reprogramming if accidently blowing power w/leds
  delay(2000);

  // Uncomment one of the following lines for your leds arrangement.
  // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  // FastLED.addLeds<NEOPIXEL, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<WS2811_400, DATA_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);

  // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
  // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}


// Pixel Painting!

int paint[] = {

  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,0,0,0,0

};

int flipped[144];

int a = 0;


void maths() {

for (int i = 1; i <= 12; i = i + 1) {

  // First item in every row

  int b = 12 - i;

  flipped[a] = paint[b];

  a =  a + 1;

  // For the next eleven items in the row.

  for (int j = 1; j <= 11; j = j + 1) {

    if (j % 2 == 0) {
      b = b + ((13 - i) * 2 - 1);
    } 
    else if (j % 2 == 1) {
      b = b + (i * 2 - 1);
    }

    flipped[a] = paint[b];

    a =  a + 1;

  }

}

}


void loop() {
  // Loop through every LED in the strip.
  for(int allLED = 0; allLED < NUM_LEDS; allLED = allLED + 1) {
    // Assign it the right colour by number.

    if (paint[allLED] == 2) leds[allLED] = CRGB::Red;

    else if (paint[allLED] == 1) leds[allLED] = CRGB::Yellow;

    else if (paint[allLED] == 0) leds[allLED]= CRGB::Blue;

    // Show the LED with the new colour.

    FastLED.show();

  }
  
}
