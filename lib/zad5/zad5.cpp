#include "zad5.h"

/*
    Zad.1.5
    Sterowanie PWM sterując jasnością świecenia diody LED
    Dioda LED:
        - połączenie anody(+) do GPIO32
        - połączenie katody(-) do GND przez rezystor 330ohm
*/
#define pwmChannel 0
#define pwmRes 8
#define pwmFreq 5000
#define pwmPin 32

const int MAX_duty = (int)(pow(2, pwmRes) - 1);
int duty;

void zad5_setup(){
    Serial.begin(115200);
    delay(1000);
    ledcSetup(pwmChannel, pwmFreq, pwmRes);
    ledcAttachPin(pwmPin, pwmChannel);
}

void zad5_loop(){
    // Increasing the LED brightness with PWM
    for(duty = 0; duty <= MAX_duty; duty++){
        ledcWrite(pwmChannel, duty);
        delay(5);
    }
    // Decreasing the LED brightness with PWM
    for(duty = MAX_duty; duty >=0; duty--){
        ledcWrite(pwmChannel, duty);
        delay(5);
    }
}

/*
    MAX_duty (duty-cycle) obliczane jest na podstawie przetwornika analogowo-cyfrowego, który ma długość 8 bitów co definiuje "pwmRes" .. co skutkuje rozdzielczością od 0 do (2^8)-1=255.
    W ten sposób uzyskujemy maksymalną wartość wypełnienia (w tym przypadku dla 8 bitów). 
*/