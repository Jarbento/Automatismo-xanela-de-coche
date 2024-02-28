// C++ code
//
/*
 * Programa para controlar a subida e baixada dunha vidro "tipo luna de coche".
 * 
 * Neste programa facemos que no momento que accionamos o pulsador (pin 2), este move o
 * motor 1 (pin 3), se non facemos nada en 7s este detense el só. Pola contra, se cando se está
 * accionando prememos o pulsador, este fará que o motor 1 pare e comece a funcionar o
 * motor 2 (pin 4) da mesma maneira que o motor 1.
 *
 * Autor: Francisco Mos
 * Data: Febreiro 2024
 */

//Declarar entradas e saídas.
#define PULS 2
#define VERDE 3
#define AMARILLO 4

//Variables globales.
int tempo = 700;
int contador = 0;
int estado_verde = 0;
int estado_amarillo = 0;

void setup(){
 pinMode(PULS, INPUT);
 pinMode(VERDE, OUTPUT);
 pinMode(AMARILLO, OUTPUT); 
 Serial.begin(9600);
}

void loop() {
 if(digitalRead(PULS) == 1) {
   //Lemos o estado do pulsador e actuamos sobre a variable do pulsador para 
   //encender o primeiro motor.
   estado_verde = !estado_verde;
   Serial.print("Estado_verde:"); Serial.println(estado_verde);
   contador = tempo * estado_verde;
   digitalWrite(VERDE, estado_verde);
   digitalWrite(AMARILLO, LOW);
   estado_amarillo = 0;
   if(estado_verde == 0){
     //No momento que pulsamos o pulsador, e o motor 1 funciona,este apagase e
     //encendese o motor 2.
     estado_amarillo = !estado_amarillo;
     Serial.print("Estado_amarillo:"); Serial.println(estado_amarillo);
     contador = tempo * estado_amarillo;
     digitalWrite(AMARILLO, estado_amarillo);
    }
    
   while(digitalRead(PULS) == 1) {
     delay(0);
   }
}
 
  if (contador > 0) {
  contador -= 1;
  delay(10);
  }
  else {
   digitalWrite(VERDE, LOW);
   digitalWrite(AMARILLO, LOW);
   estado_verde = 0;
   estado_amarillo = 0;
   //Frozase o apagado dos motores e a posta a 0 das variables dos mesmos
   //despois de pasar o tempo establecido.
 }
}
