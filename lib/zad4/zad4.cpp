#include "zad4.h"

/*
    Zad.1.4
    Wyświetlanie napięcia odczytywanego z potencjometru 0-3,3V na podstawie przeliczonych kroków 0-4096
    Potancjometr:
        - środkowa nóżka do GPIO34
        - boczna do GND
        - boczna do 3,3V
    Efekt widoczny na "serial monitor" w postaci wartości napięcia
*/

const int potPin = 34;
float voltage = 0.0;

void zad4_setup(){
    Serial.begin(115200);
    delay(1000);
}

void zad4_loop(){
    int potValue = analogRead(potPin);
    voltage = potValue * (3.3 / 4095.0);//3.3V : 4096 kroków
    Serial.println(voltage, 4); //dokładność 4 miejsc
    delay(500);
}