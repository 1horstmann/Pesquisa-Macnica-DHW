#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// https://www.embarcados.com.br/localizacao-aproximada-com-esp8266-parte-1/

const char* rpiHost = "192.168.0.24";  
 
// servidor que disponibiliza serviço de geolocalização via IP    
const char* IpApiHost = "ip-api.com";
 
WiFiClient client;

/*
 * Função que realiza GET request no site ip-api.com
 * Esse site disponibiliza uma API de geolocalização via IP
 * A função retorna um JSON com dados de geolocalização
 * Os dados de geolocalização são exibidos na pagina web em um Google Maps
 */

String makeGETlocation()
{
  Serial.println("\nRequisitando Geolocalização via IP\n");
  if ( !client.connect(IpApiHost, 80) ) {
    Serial.println("connection ao ip-api.com falhou");
    return "connection failed";
  }
  
  // Realiza HTTP GET request
  client.println("GET /json/{query}?fields=status,message,country,countryCode,region,regionName,city,zip,lat,lon,timezone,isp,org,as,query HTTP/1.1");
  client.print("Host: ");
  client.println(IpApiHost);
  client.println("Connection: close");
  client.println();
 
  // recebe o Header de resposta, 
  // cada linha do header termina com "\r\n", a ultima linha é fazia, ou seja, "\r\n" apenas
  while (client.connected()) {
    String data = client.readStringUntil('\n'); // lê uma linha até o "\n"
    Serial.println(data);
    if (data == "\r") {     // a ultima linha do header é vazia, ou seja apenas "\r\n", se lermos até "\n", temos apenas "\r"
      break;
    }
  }
  // recebe os dados de geolocalização em formato JSON e guarda na variável data
  String data = client.readStringUntil('\n');
  Serial.println("Dados de geolocalização recebidos\n");
  Serial.println(data);  
  return data; 
}
 
/*
 * Função que envia ao servidor a localização do NodeMCU
 * função realiza um POST request ao servidor no link /location
 * o servidor por sua vez exibe a localização do NodeMCU no Google Maps
 */
void makePOSTlocation()
{
    
  String location = makeGETlocation(); // guarda o JSON de geolocalização na variável location
  //Serial.println(location);
  Serial.println("\nEnviando geolocalização ao servidor\n");
  if(!client.connect(rpiHost, 3000))     // aqui conectamos ao servidor
  {
    Serial.print("Could not connect to host: \n");
    Serial.print(rpiHost);
  }
  else
  {
    // realiza HTTP POST request    
    client.println("POST /location HTTP/1.1");
    client.println("Host: 192.168.0.24");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(location.length());
    client.println();
    client.println(location);    // enviamos o JSON ao servidor
    Serial.println("\nLocalização enviada com sucesso!");
  }
}