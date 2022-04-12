/**************************************************
*   IR Music Device                               *
*   Decoding of the received commands             *
*   Transmitter side of serial communication      *
**************************************************/

#include <Arduino.h>
#include <IRremote.h>

// Definitions for the IRremote Library
#define RECV_PIN 2
IRrecv irrecv(RECV_PIN);
decode_results results;

// Command values of the remote control
#define n1              0x778C1F40
#define n2              0xB75351DF
#define n3              0x405E1F06
#define n4              0x2E00004B
#define n5              0x24957A4A
#define n6              0x12311801
#define n7              0xE973E97A
#define n8              0x84EA35D7
#define n9              0x87ECFB70
#define n0              0xFD6AED67
#define tilde_10        0xFA46837E
#define tilde_20        0x74179BD3

void setup() {
  pinMode(RECV_PIN, INPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop(){
if (irrecv.decode(&results)) {
  switch (results.value) {
    case n1:
      Serial.write(0);
      break;
    
    case n2:
      Serial.write(1);
      break;

    case n3:
      Serial.write(2);
      break;

    case n4:
      Serial.write(3);
      break;

    case n5:
      Serial.write(4);
      break;

    case n6:
      Serial.write(5);
      break;

    case n7:
      Serial.write(6);
      break;

    case n8:
      Serial.write(7);
      break;

    case n9:
      Serial.write(8);
      break;

    case n0:
      Serial.write(9);
      break;

    case tilde_10:
      Serial.write(10);
      break;

    case tilde_20:
      Serial.write(11);
      break;

    default:
      break;
    }
  }
  results.value = 0;
  irrecv.resume();
}