#include <AFMotor.h>
#include <Stepper.h>

AF_Stepper crane(50,1); // Define Nombre del motor (# de pasos por vueltas, a la puerta M1 M2)
AF_Stepper plate(200 ,2); // Define Nombre del motor (# de pasos por vueltas, a la puerta M3 M4 )
// const int buttonPin=2; // Pin del boton de encendido y apagado
int sustant; // numero de sustancias
int ciclos; // Numero de ciclos
int inside; // Tiempo dentro de la solucion en milisegundos
int coma1;
int coma2;
int coma3;
int coma4;
int dist;
String sentido;
String orden;
// volatile byte state=LOW;

void setup ()
{
  //pinMode(buttonPin,INPUT_PULLUP);
  Serial.begin (9600); // No i m p o r t a n t e
  delay(30);
  crane.setSpeed (50); // Define velocidad de giro en rpm de la grua
  plate.setSpeed(6);// Define velocidad de giro en rpm de la base
  //attachInterrupt(digitalPinToInterrupt(buttonPin),blink,CHANGE);
}

void loop () {
  if (Serial.available()){
    orden = Serial.readString();
    coma1 = orden.indexOf (",");
    sentido = orden.substring(0,coma1);
    coma2 = orden.indexOf(",",coma1+1);
    sustant = orden.substring(coma1+1,coma2).toInt();
    coma3 = orden.indexOf(",",coma2+1);
    ciclos = orden.substring(coma2+1,coma3).toInt();
    coma4 = orden.indexOf(",",coma3+1);
    inside = orden.substring(coma3+1,coma4).toInt();
    dist = orden.substring(coma4+1).toInt();
    for (int j=0;j<ciclos;j++){
      for (int i=0; i<sustant;i ++){
        crane.step(dist,BACKWARD,MICROSTEP);
        delay(inside);
        crane.step(dist,FORWARD,MICROSTEP);
        delay(inside);
        if (sentido=="FORWARD"){
          plate.step(61,FORWARD,MICROSTEP); // Define (# de pasos a realizar, 
                                                     //sentido de giro,metodo de giro (correspondiente al tipo de motor))
        } else if (sentido=="BACKWARD"){
          plate.step(61,BACKWARD,MICROSTEP); // Define (# de pasos a realizar , 
                                                     //sentido de giro, metodo de giro (correspondiente al tipo de motor))
        }
      }
    if (sentido=="FORWARD"){
      plate.step(sustant*61,BACKWARD,MICROSTEP); // Define (# de pasos a realizar , 
                                                    //sentido de giro , metodo de giro (correspondiente al tipo de motor))
    } else if (sentido=="BACKWARD"){
      plate.step(sustant*61,FORWARD,MICROSTEP); // Define (# de pasos a realizar , 
                                                    //sentido de giro , metodo de giro (correspondiente al tipo de motor))
    }
  }
  }
}
//void blink(){
//state = !state;
//}
