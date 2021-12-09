#include <Arduino.h>
#include "..\lib\definitions.hpp"

void init_hardware(void){
    pinMode(POTENCIOMETER,INPUT);
    pinMode(SENSOR_TEMPERATURE,INPUT);
    pinMode(SENSOR_MOISTURE, OUTPUT);
    pinMode(SENSOR_ACCELOMETER,INPUT);
}