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

  //api_test4();
  //api_test4();
}

void loop(){
  
  //wifi();
  //t_read();
  //api_test();
  //api_test2();
  //api_test3();

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

void api_test(void){
  
  HTTPClient http;
  //The API URL
  String request = "https://api.chucknorris.io/jokes/random";
  //Start the request
  http.begin(request);
  //Use HTTP GET request
  http.GET();
  //Response from server
  response = http.getString();
  //Parse JSON, read error if any
  DeserializationError error = deserializeJson(doc, response);
  if(error) {
     Serial.print(F("deserializeJson() failed: "));
     Serial.println(error.f_str());
     return;
  }
  //Print parsed value on Serial Monitor
  Serial.println(doc["value"].as<char*>());
  //Close connection  
  http.end();
  //Wait two seconds for next joke
  delay(2000);
}


