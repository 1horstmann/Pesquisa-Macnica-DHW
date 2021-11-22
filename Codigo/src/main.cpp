#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

/* Definindo os pinos */
#define temp      4
#define umi       2
#define led_temp  18
#define pot       35


/* Protótipos de funções */
void initializing__wifi(void);
void connecting__wifi(void);

void temperature__read(void);

void api_test(void);
void api_test2(void);
void api_test3(void);
void api_test4(void);

void initializing__hardware(void);

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  initializing__hardware();

  initializing__wifi();

  api_test4();
}

void loop(){

  connecting__wifi();

}







