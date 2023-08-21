
// #include "mpu.h"
#include <Arduino.h>
// #include <VL53L0X.h> 
#include "VL53_sensors.h"



#define SCL_SDIST 22
#define SDA_SDIST 21

// XSHUT, uma porta por sensor 
#define SDIST_1 25
#define SDIST_2 23
#define SDIST_3 13

#define N_SENSOR 3 


//Cria os objetos para cada sensor
// VL53L0X sensor[3];  //Sensor da esquerda


// int dist[N_SENSOR] ;

int X_SHUT[N_SENSOR] = { SDIST_1, SDIST_2, SDIST_3} ; 

VL53_sensors sensores;



// void sensorsInit() {

//     //Iniciando o endereçamento dos sensores
//     Wire.begin();

//     for (uint8_t i = 0; i < N_SENSOR; i++){
//       pinMode(X_SHUT[i], OUTPUT);
//       digitalWrite(X_SHUT[i], LOW);


//     }

//     for (uint8_t i = 0; i < N_SENSOR; i++){
//       pinMode(X_SHUT[i], INPUT);
//       sensor[i].init(true);
//       sensor[i].setAddress((uint8_t)0x21 + i); //endereço do sensor 1
//       sensor[i].setTimeout(40);
//     }
    
// }


// void distanceRead() {

//     for (uint8_t i = 0; i < N_SENSOR; i++){
//        dist[i] = sensor[i].readRangeSingleMillimeters();
//     }
   
// }


// void printDistances() {


//   for (uint8_t i = 0; i < N_SENSOR; i++){

//        Serial.print(" ");
//        Serial.print(String(i));
//        Serial.print(" ");
//        Serial.print(dist[i]);

//       Serial.println("\t\t");
//   }

// }



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

