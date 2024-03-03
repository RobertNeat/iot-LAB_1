#include "zad6.h"

/*
    Zad.1.6
    Sterowanie jasnością świecenia diody za pomicą odczytu potencjometru poprzez ADC oraz modulacją PWM na ponie wyjściowym.
    Potancjometr:
        - środkowa nóżka do GPIO34
        - boczna do GND
        - boczna do 3,3V
    Dioda LED:
        - połączenie anody(+) do GPIO32
        - połączenie katody(-) do GND przez rezystor 330ohm  
*/
const int potPin = 34;
const int ledPin = 32; //dla onboard LED pin 2
float voltage = 0.0;

void zad6_setup(){
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    delay(1000);
}

void zad6_loop(){
    int potValue = analogRead(potPin);
    voltage = potValue * (3.3 / 4095.0);
    int brightness = map(potValue, 0, 4095, 0, 255);//mapowanie 0-4095 na 0-255 dla analog write
    analogWrite(ledPin, brightness);
    Serial.println(voltage, 4);
    delay(500);
}