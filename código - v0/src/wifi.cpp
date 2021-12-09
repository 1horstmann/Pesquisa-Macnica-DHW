#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Site com coisas do wifi:
// https://www.usinainfo.com.br/blog/esp32-wifi-comunicacao-com-a-internet/
// https://www.arduino.cc/en/Reference/WiFi

/* Definindo os pinos */
#define temp      4
#define umi       2
#define led_temp  18
#define pot       35

// Definições da rede wifi
//const char* nome = "Macnica Dhw"; // Aqui coloca o nome da rede que vai utilizar.
//const char* senha =  "UNFQ201802"; // Aqui coloca a senha.
const char* nome = "Mi 9 Lite"; // Aqui coloca o nome da rede que vai utilizar.
const char* senha =  "nitz5555"; // Aqui coloca a senha.
WiFiServer servidor(80); // Define a porta que o servidor vai utilizar, 80 é a mais comum.


void initializing__wifi(void){
    // Inicialização da rede wifi
    Serial.println();
    Serial.print("Conectando-se a ");
    Serial.println(nome);
    WiFi.begin(nome, senha); // Inicia a tentativa de conexão

    // "WiFi.status()" retorna uma constate informando se houve problema de conexão ou não
    /*
    O que a função WiFi.status() pode retornar?
    R:  WL_CONNECTED: está conectado.
        WL_NO_SSID_AVAIL: quando a rede não for encontrada.
        WL_CONNECT_FAILED: quando as tentativas de conexão falharem.
        WL_DISCONNECTED: quando ela estiver desconectada de uma rede.
        WL_CONNECTION_LOST: quando a conexão for perdida ou interrompida.
        WL_IDLE_STATUS: quando está ou em processo de tentativas de conexão.
    */

    while(WiFi.status() != WL_CONNECTED) // Fica nesse 'while' até estar conectado à rede.
    {
    delay(500);
    Serial.println("Conectando wifi..");
    }
    Serial.println("Conectado a rede wifi");
    Serial.print("Endereço de IP:  ");
    Serial.println(WiFi.localIP()); // Printa o endereço IP da placa, que iremos acessar em outro dispositivo.

    servidor.begin(); // O servidor web é iniciado

    //WiFi.mode(WIFI_MODE_STA); // Essa função ajusta o modo de operação do chip WiFi da placa
    //Serial.println(WiFi.macAddress()); // Rretorna o endereço MAC de um dispositivo de rede (em hexadecimal) 
}


void connecting__wifi(void){
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