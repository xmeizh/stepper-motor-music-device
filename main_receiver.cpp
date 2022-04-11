/**************************************************
*   IR Music Device                               *
*   Receiver side of serial communication         *
*   Generation of the PWM signal                  *
*   Version 0.1                                   *
**************************************************/

#include <Arduino.h>

// Table for the frequencies of the tones
int tones[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};

#define Motorstep 5

unsigned long timer;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Motorstep, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    tone(Motorstep, tones[Serial.read()]);
  
    timer = millis();
  }

  if (!Serial.available() && (millis() > (timer + 200))) {
    noTone(5);
    timer = millis();
  }
}