#include "zad1.h"

/*
    Zad.1.1
    Mruganie wbudowaną diodą LED co 500 ms (0,5s) 
*/
#define LED 2

void zad1_setup(){
  pinMode(LED,OUTPUT);
}

void zad1_loop(){
    delay(500);
    digitalWrite(LED,HIGH);
    delay(500);
    digitalWrite(LED,LOW);
}