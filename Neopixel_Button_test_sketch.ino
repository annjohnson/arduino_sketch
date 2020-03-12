// a basic sketch for testing button pins and neopixels

//when the button is pressed, a neopixel sketch will trigger

#include <Adafruit_Neopixel.h>


//Definitions
#define LED_PIN 31
#define LED_COUNT 25
#define BUTTON_PIN 11

//Global variables
int buttonState = 0;

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

void setup(){
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  //read the state of the button
  buttonState = digitalRead(BUTTON_PIN);

  //if button is pressed, trigger neopixel function
  if (buttonState == HIGH){
    colorWipe(strip.Color(255,0,0), 50);
    else{
      strip.clear();
    }
  }
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
