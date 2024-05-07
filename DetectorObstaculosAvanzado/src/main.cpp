#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define pingPin 5
#define DO 523
#define DOs 1027
#define Buzzpin 13
#define SERVOMIN 320
#define SERVOSTOP 380
#define SERVOMAX 440

#define servo_left 0
#define servo_right 1

// put function declarations here:
void detectWall();
void sound_warning();
void sound_danger();
void emergencyRotation();

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:
  detectWall();
}

// put function definitions here:
void detectWall() {
  long duration, cm;

  pinMode(pingPin, OUTPUT);

  digitalWrite(pingPin,LOW);
  delayMicroseconds(10);

  digitalWrite(pingPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(pingPin,LOW);

  pinMode(pingPin, INPUT);

  duration = pulseIn(pingPin,HIGH);
  cm = duration / 29 / 2;

  Serial.print("distance: ");
  Serial.print(cm);
  Serial.println(" cm");
  delay(100);
  if (cm <= 10)
  {
    sound_warning();
    emergencyRotation();
  } else {
    pwm.setPWM(servo_left,0,SERVOMAX);
    pwm.setPWM(servo_right,0,SERVOMAX);
  }
}

void sound_warning() {
  tone(Buzzpin,DO);
  delay(300);
  noTone(Buzzpin);
}

void sound_danger() {
  tone(Buzzpin, DOs);
  delay(300);
  noTone(Buzzpin);
}

void emergencyRotation() {
  pwm.setPWM(servo_left,0,SERVOSTOP);
  pwm.setPWM(servo_right,0,SERVOMIN);
  delayMicroseconds(10);
}