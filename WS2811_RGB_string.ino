#include "FastLED.h"
#define NUM_LEDS 49
// Data pin that led data will be written out over
#define DATA_PIN 3

CRGB leds[NUM_LEDS];// This is an array of leds.  One item for each led in your strip.

int bank_1_size = 10;  //Number of LEDs in bank 1
int bank_2_size = 10;  //Number of LEDs in bank 2
int c; //bank1 display
int d; //bank2 display
int offset = 25; //Number of LEDs between banks
int bank2; //bank 2 start location


void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);

      FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);

}

// Main endless Loop
void loop() {
   
   for(int bank1 = 0; bank1 < NUM_LEDS; bank1 = bank1 + 1) {
      // Turn our current led on to white, then show the leds

 if (bank1 - offset <= -1)
 { bank2 = NUM_LEDS + bank1 - offset ;}

 else
 { bank2 = bank1 - offset ;}
 
      leds[bank1] = CRGB::Red; //colour of bank1
      leds[bank2] = CRGB::Green; //colour of bank 2

      // Show the leds 
      FastLED.show();

      // Wait a little bit
      delay(40);

      // Turn our current led back to black for the next loop around
    if (bank1 < bank_1_size) 
    { c = (bank1 + NUM_LEDS - bank_1_size );} 
    else 
    { c = (bank1 - bank_1_size );}
      leds[c] = CRGB::Blue; //colour between bank1 & bank2
      
 if (bank2 < bank_2_size ) 
    { d = (bank2 + NUM_LEDS - bank_2_size );} 
    else 
    { d = (bank2 - bank_2_size   );}
      leds[d] = CRGB::Yellow; //colour between bank2 and bank 1
     
    
      
      
   }
}
