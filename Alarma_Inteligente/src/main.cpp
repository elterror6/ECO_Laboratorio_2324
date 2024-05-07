#include <Arduino.h>
#define red_led 12
#define green_led 9
#define Buzzpin 13
#define Buttonpin 11
#define DO 523
#define MI 659

volatile bool alarm_on = true;
// put function declarations here:
void LEDS();
void Buzzer();
void switch_alarm_state();

void setup() {
  Serial.begin(9600);
  pinMode(red_led,OUTPUT);
  pinMode(green_led,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Buttonpin), switch_alarm_state, RISING);
}

void loop() {
  while (alarm_on)
  {
    LEDS();
    Buzzer();
  }
  
}

// put function definitions here:
void LEDS () {
  digitalWrite(red_led,HIGH);
  delay(1000);
  digitalWrite(red_led,LOW);
  
  digitalWrite(green_led,HIGH);
  delay(1000);
  digitalWrite(green_led,LOW);
}

void Buzzer () {
  tone(Buzzpin,MI);
  delay(300);

  tone(Buzzpin,DO);
  delay(300);
}

void switch_alarm_state () {
  alarm_on = !alarm_on;
}