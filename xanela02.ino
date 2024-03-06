// C++ code
//
/*
 * Programa para controlar a subida e baixada dunha vidro "tipo luna de coche".
 * 
 * Neste programa facemos que no momento que accionamos o pulsador (pin 2), este move o
 * motor 1 (pin 3), este funcionará hasta que a ventana chegue ao Final de Carrera 1 ou hasta que novamente se prema o pulsador de accionamento.
 * No momento que estean parados, se previamente se accionou un dos finais de carreira, cando se lle dea ao pulsador iniciarase o motor contrario.
 * Final de carreira do motor 1: PIN 5.
 * Final de carreira do motor 2: PIN 6.
 * Control do relé do motor 1: PIN 3.
 * Control do relé do motor 2: PIN 4.
 * Accionamento: PIN 2.
 *
 * Autor: Francisco Mos Santamaría.
 * Data: Marzo 2024.
 */

//Definimos as entradas e salidas.
#define PULS 2
#define VERDE 3
#define AMARILLO 4
#define FCVERDE 5
#define FCAMARILLO 6

//Variables globales.
bool estado_verde = 0;
bool estado_amarillo = 0;
int pulsaciones = 0;

//Declarar entradas e saídas.
void setup(){
 pinMode(PULS, INPUT);
 pinMode(FCVERDE, INPUT);
 pinMode(FCAMARILLO, INPUT); 
 pinMode(VERDE, OUTPUT);
 pinMode(AMARILLO, OUTPUT); 
 Serial.begin(9600);
}

void loop() {
 if(digitalRead(PULS) == 1) {
   //Lemos cada unha das pulsacions do pulsador.
   pulsaciones += 1;
   Serial.print("Pulsaciones:"); Serial.println(pulsaciones);
   if(pulsaciones == 1){
     //Facemos que arranque o motor 1.
     estado_verde = !estado_verde;
     Serial.print("Estado_verde:"); Serial.println(estado_verde);
     digitalWrite(VERDE, estado_verde);
   }
   if(pulsaciones == 2){
     //Facemos que o motor 1 pare.
     estado_verde = !estado_verde;
     Serial.print("Estado_verde:"); Serial.println(estado_verde);
     digitalWrite(VERDE, estado_verde);
   }
   if(pulsaciones == 3){
     //Facemos que arranque o motor 2.
     estado_amarillo = !estado_amarillo;
     Serial.print("Estado_amarillo:"); Serial.println(estado_amarillo);
     digitalWrite(AMARILLO, estado_amarillo);
   }
   if(pulsaciones == 4){
     //Facemos que o motor 2 pare.
     estado_amarillo = !estado_amarillo;
     Serial.print("Estado_amarillo:"); Serial.println(estado_amarillo);
     digitalWrite(AMARILLO, estado_amarillo);
     pulsaciones = 0;
   }
   	while(digitalRead(PULS) == 1) {
    	delay(0);
   	}
   } 
  if(digitalRead(FCVERDE) == 1 && pulsaciones == 1){
    //Lemos o Final de carreira do motor 1, solamente no  momento no que este estea funcionando, e si se preme forzamos o paso ao siguiente estado.
    pulsaciones += 1;
    Serial.print("Pulsaciones:"); Serial.println(pulsaciones);
    estado_verde = !estado_verde;
    digitalWrite(VERDE, estado_verde);
    while(digitalRead(FCVERDE) == 1) {
    	delay(0);
   }
  }
  if(digitalRead(FCAMARILLO) == 1 && pulsaciones == 3){
    //Lemos o Final de carreira do motor 2, solamente no  momento no que este estea funcionando, e si se preme forzamos o paso ao siguiente estado.
  	pulsaciones += 1;
  	Serial.print("Pulsaciones:"); Serial.println(pulsaciones);
  	estado_amarillo = !estado_amarillo;
  	digitalWrite(AMARILLO, estado_amarillo);
    pulsaciones = 0;
    while(digitalRead(FCAMARILLO) == 1) {
    	delay(0);
    }
  }
}
