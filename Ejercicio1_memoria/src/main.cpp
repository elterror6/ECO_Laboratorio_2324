#include <Arduino.h>

int a;
static int b;
void setup() {
  Serial.begin(9600);
  int* dir_b = &b;
  char text[64];
  sprintf(text, "a = %d ,b = %X",a,dir_b);
  Serial.print(text);
}

void loop() {
}
