#include <Arduino.h>
#define pingPin 5
#define DO 523
#define TRUE 1
#define FALSE 0
#define Buzzpin 13

void setup() {
  Serial.begin(9600);
}

void loop() {
  long duration, cm, value;

  pinMode(pingPin, OUTPUT);

  digitalWrite(pingPin,LOW);
  delayMicroseconds(10);

  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(pingPin, LOW);
  
  pinMode(pingPin, INPUT);

  duration = pulseIn(pingPin, HIGH);

  cm = duration / 29 /2;

  if (cm > 5) {
    value= TRUE;
  }  else {
    value= FALSE;
  }
  
  if (value == TRUE)
  {
    tone(Buzzpin,DO);
    delay(300);
  }
  
}

