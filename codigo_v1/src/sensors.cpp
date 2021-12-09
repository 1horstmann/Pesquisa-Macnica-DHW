#include <Arduino.h>
#include "..\lib\definitions.hpp"


 
float SENSORS__TEMPERATURA_READING(void)
{
    float measure = analogRead(SENSOR_TEMPERATURE);
    measure = measure * 3.3 / 4095.0; // conversão bits para tensão
    measure = measure * 100; // conversão tensão para temepratura

    return measure
}


float SENSORS__MOISTURE_READING(void)
{
    


 
}


float SENSORS__ACCELEROMETER_READING(void)
{



}



