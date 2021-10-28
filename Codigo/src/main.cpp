#include <Arduino.h>
#include <WiFi.h>

// Site com coisas do wifi:
// https://www.usinainfo.com.br/blog/esp32-wifi-comunicacao-com-a-internet/

/* Definindo os pinos */
#define temp   4
#define umi    2
#define led_temp 18 

/* Definindo constantes */
#define periodo_leitura 3000

/* Protótipos de funções */
void t_read(void);

// Definições da rede wifi
const char* nome = "AP_NITZ_2G"; // Aqui coloca o nome da rede que vai utilizar.
const char* senha =  "nitz1234"; // Aqui coloca a senha.
WiFiServer servidor(80); // Define a porta que o servidor vai utilizar, 80 é a mais comum.

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  /* Definindo os IO */
  pinMode(temp,INPUT);
  pinMode(umi,INPUT);
  pinMode(led_temp, OUTPUT);
  pinMode(2,OUTPUT);

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

void loop(){
  WiFiClient cliente = servidor.available();
  if (cliente) {
    Serial.println("Novo cliente");
    String currentLine = "";
    while (cliente.connected()) {
      if (cliente.available()) {
        char c = cliente.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            cliente.println("HTTP/1.1 200 OK");
            cliente.println("Content-type:text/html");
            cliente.println();
            cliente.print("Click <a href=\"/H\">here</a> to turn the LED on pin 2 on.<br>");
            cliente.println();
            cliente.print("Click <a href=\"/L\">here</a> to turn the LED on pin 2 off.<br>");
            cliente.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(2, HIGH);
          Serial.println("CLIOCU EM OUTRO");
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(2, LOW);
          Serial.println("CLIOCU EM UM");
        }
      }
    }

    //cliente.println("Oi");
    //cliente.println("Tudo bem?");

    cliente.stop();
    Serial.println("Client Disconnected.");
  }
  
  //t_read();

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

