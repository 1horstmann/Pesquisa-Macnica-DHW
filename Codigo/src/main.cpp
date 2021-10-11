#include <Arduino.h> // Biblioteca do FreeRTOS para o Arduino
#include <freertos/FreeRTOS.h>
#include <freertos/task.h> // Biblioteca para utilização das tasks
// #include <math.h> // Biblioteca para funções matemáticas

// Definir os pinos dos leds
#define led_amarelo   4
#define led_vermelho  6
#define led_verde     8
 
 void led1Task(void *arg);

//Tasks
TaskHandle_t    led1TaskH;
  
void setup() {
    // Inicializa Serial
    Serial.begin(9600);
    

    
    // Define os leds como saída
    pinMode(led_verde, OUTPUT);
    pinMode(led_amarelo, OUTPUT);
    pinMode(led_vermelho, OUTPUT);
     
    // Cria tarefa led1Task
    xTaskCreate(led1Task,     // Função
                "led1Task",   // Nome
                128,          // Pilha
                NULL,         // Parâmetro
                1,            // Prioridade
                &led1TaskH);  // Identificador
}
 
void loop() {
    // Nada é executado aqui, as tarefas estão nas funções abaixo
}
 
  // Led1Task
  // Pisca led verde com frequência de 1Hz


 