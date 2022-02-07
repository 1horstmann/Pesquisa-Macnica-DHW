#include <Arduino.h>
#include <ClosedCube_HDC1080.h>
#include "..\lib\definitions.hpp"

void HARDWARE__INIT(void){
    pinMode(POTENCIOMETER,INPUT);
    pinMode(SENSOR_TEMPERATURE,INPUT);
    pinMode(SENSOR_MOISTURE, OUTPUT);
    pinMode(SENSOR_ACCELOMETER,INPUT);

    hdc1080.begin(0x40);
}


