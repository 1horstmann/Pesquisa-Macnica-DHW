#include <Arduino.h>
#include <ClosedCube_HDC1080.h>


#include "..\lib\definitions.hpp"

ClosedCube_HDC1080 hdc1080;


float SENSORS__TEMPERATURA_READING(void)
{
    float measure = hdc1080.readTemperature();
    return measure;
}


float SENSORS__MOISTURE_READING(void)
{
    float measure = hdc1080.readHumidity();
    return measure;
}


float SENSORS__ACCELEROMETER_READING(void)
{



}



