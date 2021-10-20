#include <Arduino.h> // Biblioteca do FreeRTOS para o Arduino
#include <freertos/FreeRTOS.h>
#include <freertos/timers.h>
// #include <freertos/task.h> // Biblioteca para utilização das tasks
// #include <math.h> // Biblioteca para funções matemáticas

/* Definindo os pinos */
#define temp   4
#define umi    2

/* Definindo constantes */
#define periodo_total_leitura 3000
#define periodo_sem_leitura 2000

static TimerHandle_t t_read = NULL;

/* Protótipos de funções */
void leitura_temp(TimerHandle_t t);

void setup(){

  /* Comunicação Serial */
  Serial.begin(115200);

  /* Definindo os IO */
  pinMode(temp,INPUT);
  pinMode(umi,INPUT);

  /* Criando as Tarefas de Timers */
  t_read = xTimerCreate("t_read", pdMS_TO_TICKS(periodo_total_leitura), pdTRUE, 0, leitura_temp);

  /* Inicializando as Tarefas */
  xTimerStart(t_read, portMAX_DELAY);

}

void loop(){

}

/* Função de le a temperatura */
void leitura_temp(TimerHandle_t t){
  
  float l_temp = analogRead(temp)*3.3/4095.0; // Conversão bits para tensão
  float tempC = l_temp*100.0; // Conversão tensão para temperatura

  Serial.print("Temperatura: ");
  Serial.print((unsigned)tempC);
  Serial.println(" °C");

  vTaskDelay(pdMS_TO_TICKS(periodo_sem_leitura));

}
 