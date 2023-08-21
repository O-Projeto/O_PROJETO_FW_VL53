

#include <Arduino.h>
#include "VL53_sensors.h"

//I2c PINS 

#define SCL_SDIST 22
#define SDA_SDIST 21


//X SHUT PINS 

#define SDIST_1 25
#define SDIST_2 23
#define SDIST_3 13

#define N_SENSOR 3 





int X_SHUT[N_SENSOR] = { SDIST_1, SDIST_2, SDIST_3} ; 

VL53_sensors sensores;






void setup(){

  Serial.begin(112500);


  sensores.sensorsInit();


}


void loop(){
 
 sensores.distanceRead();

  for (uint8_t i = 0; i < N_SENSOR; i++){

       Serial.print(" ");
       Serial.print(String(i));
       Serial.print(" ");
       Serial.print(sensores.dist[i]);

  }
      Serial.println("\t\t");
  
}   

