#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

/* Definindo os pinos */
#define temp      4
#define umi       2
#define led_temp  18
#define pot       35

void initializing__hardware(void){
    /* Definindo os IO */
    pinMode(temp,INPUT);
    pinMode(umi,INPUT);
    pinMode(led_temp, OUTPUT);
    pinMode(pot,INPUT);
}

