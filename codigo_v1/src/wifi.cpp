#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

/* Site com coisas do wifi:
 * https://www.usinainfo.com.br/blog/esp32-wifi-comunicacao-com-a-internet/
 * https://www.arduino.cc/en/Reference/WiFi
 */

const char* nome;
const char* senha;

WiFiServer WIFI__DEFINITIONS(void){
    /* Definições da rede wifi */
    nome = "Macnica Dhw"; // Aqui coloca o nome da rede que vai utilizar.
    senha =  "UNFQ201802"; // Aqui coloca a senha.
    //nome = "Mi 9 Lite"; // Aqui coloca o nome da rede que vai utilizar.
    //senha =  "nitz5555"; // Aqui coloca a senha.
    WiFiServer servidor(80); // Define a porta que o servidor vai utilizar, 80 é a mais comum.

    return servidor;
}

void WIFI__INIT(WiFiServer servidor){
    /* Inicialização da rede wifi */
    Serial.println();
    Serial.print("Conectando-se a ");
    Serial.println(nome);
    WiFi.begin(nome, senha); // Inicia a tentativa de conexão

    while(WiFi.status() != WL_CONNECTED) // Fica nesse 'while' até estar conectado à rede.
    {
    delay(500);
    Serial.println("Conectando wifi..");
    }
    Serial.println("Conectado a rede wifi");
    Serial.print("Endereço de IP:  ");
    Serial.println(WiFi.localIP()); // Printa o endereço IP da placa, que iremos acessar em outro dispositivo.

    servidor.begin(); // O servidor web é iniciado
}