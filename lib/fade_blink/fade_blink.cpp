#include "fade_blink.h"

/*
    Powolne mruganie wbudowaną diodą LED (można zmienić na sterowanie diodą poprzez pin zewnętrzny)
*/
void LedBlink(int,int); //softly blink internal led
const int ledPin = LED_BUILTIN;


void fade_blink_setup(){
    pinMode(LED_BUILTIN,OUTPUT);
    Serial.begin(921600); //<- jeżeli w konfiguracji się ustawi na to samo "monitor_speed"
    Serial.println("Setup part execute"); 
}

void fade_blink_loop(){
    LedBlink(8,1000);
}

void LedBlink(int fading, int state)
{
  //fading speed - time of each fading step (8)
  //state - time of the full_on/full_of state (1000)
    
  // Fade in
  for (int brightness = 0; brightness <= 255; brightness++) {
    analogWrite(ledPin, brightness);
    delay(fading);  // Adjust the delay to control the fading speed
  }

  delay(state);

  // Fade out
  for (int brightness = 255; brightness >= 0; brightness--) {
    analogWrite(ledPin, brightness);
    delay(fading);  // Adjust the delay to control the fading speed
  }

  delay(state);
}
