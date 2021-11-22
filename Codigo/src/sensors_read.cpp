#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

/* Definindo os pinos */
#define temp      4
#define umi       2
#define led_temp  18
#define pot       35


/* Função que le a temperatura */
void temperature__read(void){
    float l_temp = analogRead(temp)*3.3/4095.0; // Conversão bits para tensão
    float tempC = l_temp*100.0; // Conversão tensão para temperatura

    Serial.println(analogRead(temp));
    Serial.print("Temperatura: ");
    Serial.print((unsigned)tempC);
    Serial.println(" °C");
    digitalWrite(led_temp, !digitalRead(led_temp));
    vTaskDelay(pdMS_TO_TICKS(3000));
}