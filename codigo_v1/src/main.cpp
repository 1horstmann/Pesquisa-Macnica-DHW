#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "..\lib\definitions.hpp"
#include "..\lib\hardware.hpp"
#include "..\lib\wifi.hpp"

void setup(){

/* Comunicação Serial */
  Serial.begin(115200);

  HARDWARE__INIT();

  WiFiServer servidor = WIFI__DEFINITIONS();
  WIFI__INIT(servidor);

}

void loop(){


}







