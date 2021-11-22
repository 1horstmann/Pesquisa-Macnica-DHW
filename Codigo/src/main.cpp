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

/* Definindo constantes */
#define periodo_leitura 3000

/* Protótipos de funções */
void wifi(void);
void t_read(void);
void api_test(void);
void api_test2(void);
void api_test3(void);
void api_test4(void);

// Definições da rede wifi
const char* nome = "Macnica Dhw"; // Aqui coloca o nome da rede que vai utilizar.
const char* senha =  "UNFQ201802"; // Aqui coloca a senha.
WiFiServer servidor(80); // Define a porta que o servidor vai utilizar, 80 é a mais comum.

//String for storing server response
String response = "";
//JSON document
DynamicJsonDocument doc(2048);

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  /* Definindo os IO */
  pinMode(temp,INPUT);
  pinMode(umi,INPUT);
  pinMode(led_temp, OUTPUT);
  pinMode(pot,INPUT);

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

  api_test4();
  //api_test4();
}

void loop(){
  
  //wifi();
  //t_read();
  //api_test();
  //api_test2();
  //api_test3();

}







