#include <FastLED.h>

#define DATA_PIN    6   
#define LED_COUNT   120 
#define BRIGHTNESS  128 

CRGB leds[LED_COUNT];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, LED_COUNT);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  rainbowCycle(50);
}

void rainbowCycle(int speed) {
  for (int i = 0; i < 255; i++) {
    fill_rainbow(leds, LED_COUNT, i);
    FastLED.show();
    delay(speed);
  }
}
