#include <Arduino.h> // Biblioteca do FreeRTOS para o Arduino
// #include <freertos/FreeRTOS.h>
// #include <freertos/task.h> // Biblioteca para utilização das tasks
// #include <math.h> // Biblioteca para funções matemáticas

// Definir os pinos dos leds
#define temperatura   4
#define umidade       2

int x, y;

void setup(){
  Serial.begin(115200);

  pinMode(temperatura,INPUT);
  pinMode(umidade,INPUT);


}

void loop(){

  x = analogRead(temperatura);
  y = analogRead(umidade);

  Serial.println(x);
  Serial.println(y);

  // delay(200);
}
 