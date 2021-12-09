#include <Arduino.h>
#include "..\lib\definitions.hpp"
#include "..\lib\hardware.hpp"

void setup(){

/* Comunicação Serial */
  Serial.begin(115200);

  HARDWARE__INIT();


}

void loop(){


}







