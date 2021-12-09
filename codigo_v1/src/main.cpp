#include <Arduino.h>
#include "..\lib\definitions.hpp"
#include "..\lib\hardware.hpp"
#include "..\lib\wifi.hpp"

void setup(){

/* Comunicação Serial */
  Serial.begin(115200);

  HARDWARE__INIT();

  WIFI__INIT();

}

void loop(){


}







