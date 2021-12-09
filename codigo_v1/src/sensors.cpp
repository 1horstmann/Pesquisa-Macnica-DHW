#include <Arduino.h>
#include "..\lib\hardware.hpp"


 
float SENSORS__TEMPERATURA_READING()
{
    float measure = analogRead(SENSOR_TEMPERATURE);
    measure = measure * 3.3 / 4095.0; // conversão bits para tensão
    measure = measure * 100; // conversão tensão para temepratura

    return measure
}


void SENSORS__MOISTURE_READING()
{
    


 
}


void SENSORS__ACCELEROMETER_READING()
{



}



