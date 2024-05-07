#include <Arduino.h>
// Demuestra que el puntero de pila crece a partir del límite superior de la SRAM hacia posiciones de memoria descendentes. 
void setup() {
  // Sabemos que las variables locales se guardan en el stack
  Serial.begin(9600);
  int a = 10;
  int b = 11;
  // Si dirección de a > b demostramos el ejercicio
  int* a_dir = &a;
  int* b_dir = &b;
  char text[64];
  sprintf(text, "Dirección de a: %x\nDirección de b: %x\n",a_dir,b_dir);
  Serial.print(text);
}

void loop() {
  // put your main code here, to run repeatedly:
}