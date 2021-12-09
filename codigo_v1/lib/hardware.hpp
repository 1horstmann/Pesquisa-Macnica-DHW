#ifndef HARDWARE
#define HARDWARE

/* DEFINIÇÕES DOS PINOS */
#define POTENCIOMETER       3
#define SENSOR_TEMPERATURE  4
#define SENSOR_MOISTURE     2
#define SENSOR_ACCELOMETER  2

/* Protótipos de funções */
void initializing__wifi(void);
void connecting__wifi(void);

void temperature__read(void);

void initializing__hardware(void);

void api_test1();
void api_test2();
void api_test3();
void api_test4();

String makeGETlocation();
void makePOSTlocation();



#endif