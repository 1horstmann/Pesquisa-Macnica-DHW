#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

void wifi(void){
  // Cria uma variável 'cliente' e verifica se existe um cliente conectado.
  WiFiClient cliente = servidor.available();

  int controle = 0;

  if (cliente) { // Entra aqui se tiver um cliente conectado.
    Serial.println("Novo cliente");
    
  while (cliente.connected()) { // Fica nesse 'while' até o cliente se desconectar
    if (cliente.available()) {
      cliente.println(analogRead(pot)); // Printa coisas que o cliente pode ver por meio do IP
      Serial.println(analogRead(pot));  
      delay(500);
      
      if (controle){ // Nunca vai entrar aqui do jeito que está, só pra mostrar a função
        cliente.stop(); // Desconecta o cliente
        Serial.println("Cliente desconectado");
      }
    }    
  }
}
}