#include "zad2.h"

/*
    Zad.1.2
    Odczyt wartości analogowych z potencjometru (10 kiloomów)
    Potencjometr:
        - środkowa nóżka do GPIO34
        - boczna do GND
        - boczna do 3,3V
    Efekt widoczny na "serial monitor" w postaci liczb 0-4095
*/

  const int potPin = 34;
  int potValue = 0;

void zad2_setup(){
    Serial.begin(115200);
    delay(1000);
}

void zad2_loop(){
    potValue = analogRead(potPin); //odczyt wartości potencjometru
    Serial.println(potValue);
    delay(500);
}