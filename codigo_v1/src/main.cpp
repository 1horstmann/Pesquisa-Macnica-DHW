#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "..\lib\hardware.hpp"





void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  initializing__hardware();

  initializing__wifi();

  //api_test4();
  //api_test4();
}

void loop(){

  //connecting__wifi();
  makePOSTlocation();

}







