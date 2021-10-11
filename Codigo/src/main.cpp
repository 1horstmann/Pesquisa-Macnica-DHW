#include <Arduino.h>
#include <FreeRTOS.h>

  void teste1(void);
  extern void teste2(void);

void setup() {
  Serial.begin(9600);

  teste1();
  teste2();

}

void loop() {
  // put your main code here, to run repeatedly:
}


void teste1(void){
  Serial.println("teste1");

}

void teste3(void){
  Serial.println("alo alo alo");
}


void teste3(void){
  Serial.println("ai aia ia");
}

void teste3(void){
  Serial.println("ai aia ia");
}
