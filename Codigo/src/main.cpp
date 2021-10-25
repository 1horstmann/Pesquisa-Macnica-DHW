#include <Arduino.h>
#include <WiFi.h>
//#include <SPI.h>

/* Definindo os pinos */
#define temp   4
#define umi    2
#define led_temp 18 

/* Definindo constantes */
#define periodo_leitura 3000


/* Protótipos de funções */
void t_read(void);

// Definições da redo wifi
char* nome = "macnica";
char* senha =  "12345678";
//WiFiServer server(80);

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  // Inicialização da rede wifi
  WiFi.begin(nome, senha);

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

  while(WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Conectando wifi..");
  }
  Serial.println("Conectado a rede wifi");

  /* Definindo os IO */
  pinMode(temp,INPUT);
  pinMode(umi,INPUT);
  pinMode(led_temp, OUTPUT);

}

void loop(){
  
  
  t_read();

}

/* Função que le a temperatura */
void t_read(void){
    float l_temp = analogRead(temp)*3.3/4095.0; // Conversão bits para tensão
    float tempC = l_temp*100.0; // Conversão tensão para temperatura

    Serial.println(analogRead(temp));
    Serial.print("Temperatura: ");
    Serial.print((unsigned)tempC);
    Serial.println(" °C");
    digitalWrite(led_temp, !digitalRead(led_temp));
    vTaskDelay(pdMS_TO_TICKS(periodo_leitura));
}

