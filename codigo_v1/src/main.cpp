#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "../lib/definitions.hpp"


/* Protótipos de funções */
void initializing__wifi(void);
void connecting__wifi(void);

void temperature__read(void);

void initializing__hardware(void);

void api_test1();
void api_test2();
void api_test3();
void api_test4();

String makeGETlocation();
void makePOSTlocation();



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







