#include <Arduino.h> // Biblioteca do FreeRTOS para o Arduino
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
// #include <freertos/task.h> // Biblioteca para utilização das tasks
// #include <math.h> // Biblioteca para funções matemáticas

/* Definindo os pinos */
#define temp   4
#define umi    2

/* Definindo constantes */
#define periodo_leitura 3000

/* Criando as tarefas */
TaskHandle_t t_readH;

/* Protótipos de funções */
void t_read(void *arg);

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  /* Definindo os IO */
  pinMode(temp,INPUT);
  pinMode(umi,INPUT);

  /* Criando as Tarefas */
  xTaskCreate(t_read, "t_read", 128, NULL, 1, &t_readH);

}

void loop(){}

/* Função de le a temperatura */
void t_read(void *arg){
  while(1){
    float l_temp = analogRead(temp)*3.3/4095.0; // Conversão bits para tensão
    float tempC = l_temp*100.0; // Conversão tensão para temperatura

    Serial.print("Temperatura: ");
    Serial.print((unsigned)tempC);
    Serial.println(" °C");

    vTaskDelay(pdMS_TO_TICKS(periodo_leitura));
  }
}
 