#include <SharpIR.h>

#define ir A0
#define model 1080

SharpIR sharp(ir, 25, 93, model);

// ir: Pin Analogico donde se conecta el sensor
// 25: El numero de lecturas que la libreria hara antes de hacer el calculo de distancias 
// 93: la diferencia entre dos medias consecutivas tomadas como validas
// model: Determina el Modelo de tu sensor :  1080 for GP2Y0A21Y
//                                            20150 for GP2Y0A02Y



void setup(){
  
  Serial.begin(9600);
  pinMode (ir, INPUT);
  
}

void loop(){

  delay(2000);    // Retardo entre cada medicion
  unsigned long pepe1=millis();  // toma el tiempo de cada loop
  
  int dis=sharp.distance();  // retorna la distancia


  Serial.print("Distancia: ");  
  Serial.println(dis);
  
  unsigned long pepe2=millis()-pepe1;  // retornal el tiempo de cada medicion
  Serial.print("Tiempo (ms): ");
  Serial.println(pepe2);  
}
  

