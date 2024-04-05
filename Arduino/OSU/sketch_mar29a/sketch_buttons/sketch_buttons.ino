#include <Keyboard.h>

const int buttonXPin = 2;  
const int buttonZPin = 3;  

const unsigned long debounceDelay = 50; 
const unsigned long longPressDelay = 500; 

unsigned long lastDebounceTimeX = 0;
unsigned long lastDebounceTimeZ = 0;
bool xPressed = false;
bool zPressed = false;

void setup() {
  pinMode(buttonXPin, INPUT_PULLUP);
  pinMode(buttonZPin, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  if (digitalRead(buttonXPin) == LOW) {
    if (!xPressed && (millis() - lastDebounceTimeX) > debounceDelay) {
      Keyboard.press('x');
      xPressed = true;
    }
    lastDebounceTimeX = millis();
  } else {
    if (xPressed) {
      Keyboard.release('x');
      xPressed = false;
    }
  }

  if (digitalRead(buttonZPin) == LOW) {
    if (!zPressed && (millis() - lastDebounceTimeZ) > debounceDelay) {
      Keyboard.press('z');
      zPressed = true;
    }
    lastDebounceTimeZ = millis();
  } else {
    if (zPressed) {
      Keyboard.release('z');
      zPressed = false;
    }
  }

  if (digitalRead(buttonXPin) == LOW && digitalRead(buttonZPin) == LOW) {
    if ((millis() - lastDebounceTimeX) > longPressDelay && (millis() - lastDebounceTimeZ) > longPressDelay) {
    }
  }
}
