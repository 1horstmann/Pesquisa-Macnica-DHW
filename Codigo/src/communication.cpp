#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

//String for storing server response
String response = "";
//JSON document
DynamicJsonDocument doc(2048);


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



void api_test2(){
  HTTPClient http;   

   http.begin("http://jsonplaceholder.typicode.com/posts");  //Specify destination for HTTP request
   http.addHeader("Content-Type", "text/plain");             //Specify content-type header

   int httpResponseCode = http.POST("POSTING from ESP32");   //Send the actual POST request

   if(httpResponseCode>0){

    String response = http.getString();                       //Get the response to the request

    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer

   }else{

    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);

   }

   http.end();
   
}

void api_test3(){
  HTTPClient http; 
   //StaticJsonDocument<250> jsonDocument;  
//   char buffer[250];

    http.begin("http://dummy.restapiexample.com/api/v1/create");  //Specify destination for HTTP request
    http.addHeader("Content-Type", "application/json");             //Specify content-type header

    // jsonDocument.clear();  
    // jsonDocument["name"] = "happy";
    // jsonDocument["salary"] = "10000000000";
    // jsonDocument["age"] = "3";
    // serializeJson(jsonDocument, buffer);

    //jsonDocument = {"name":"happy","salary":"10000","age":"3"};

    String teste = "name=berinjelafria&salary=100000&age=3";
    int httpResponseCode = http.POST(teste);
    //int httpResponseCode = http.POST(jsonDocument);

    if(httpResponseCode>0){

    String response = http.getString();                       //Get the response to the request

    Serial.println(httpResponseCode);   //Print return code
    Serial.println(response);           //Print request answer

   }else{

    Serial.print("Error on sending POST: ");
    Serial.println(httpResponseCode);

   }

   http.end();
   
}

void api_test4(){
    HTTPClient http;
  //The API URL
  String request = "http://dummy.restapiexample.com/api/v1/employee/7335";
  //Start the request
  http.begin(request);
  //Use HTTP GET request
  http.GET();
  //Response from server
  String response = "";
  response = http.getString();
  Serial.println(response);
  //Parse JSON, read error if any
  //DeserializationError error = deserializeJson(doc, response);
  /*if(error) {
     Serial.print(F("deserializeJson() failed: "));
     Serial.println(error.f_str());
     return;
  }
  //Print parsed value on Serial Monitor
  Serial.println(doc["value"].as<char*>());
  //Close connection  */
  http.end();
}
