#include <Arduino.h> // Biblioteca do FreeRTOS para o Arduino
#include <freertos/FreeRTOS.h>
#include <freertos/task.h> 
#define led_amarelo   4
#define led_vermelho  6
#define led_verde     8

void led1Task(void *arg) {
    while(1) { // Loop infinito
        digitalWrite(led_verde, HIGH);    // Liga o led
        vTaskDelay(pdMS_TO_TICKS(500));   // Espera 0.5s
        digitalWrite(led_verde, LOW);     // Desliga o led
        vTaskDelay(pdMS_TO_TICKS(500));   // Espera 0.5s
    }
}
// akojoiasnxnasnxoanwoxoca

// Alo Alo Alo 