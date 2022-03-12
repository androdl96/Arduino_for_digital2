/*
  Borrador de programa para proyecto final de electrónica digital.

  Inicializa el servo motor y un medidor de voltaje(potenciómetro en configuración de divisor de voltaje).
  1-Mientras el voltaje medido sea menor que .5V, el servo se mantiene en posición 0. 
  2-Ajustar brazo del servo al electrodo central de la cubeta por donde debe pasar un voltaje "residual" pequeño.
  3-Conectar la fuente de corriente, el voltaje residual es mayor que .5V y echa a andar el servo.
  4-El loop se detiene cuando el voltaje medido alcanza un máximo cerca de la posición del electrodo externo.
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

// the setup routine runs once when you press reset:
void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(9); 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  float median_volt = 0;
  
  myservo.write(0);
  
  for (int i=0; i<=10; i+=1)
  {
    median_volt = median_volt + analogRead(A0)* (5.0 / 1023.0);
    //delay (100);
    //Serial.println(median_volt);
  }
  
  //Serial.println(median_volt);
  delay (100);
  
  if(median_volt > 3)
  { float ang=0;
    for (pos = 0; pos <= 10; pos += 1) 
    { 
      median_volt=0;
      myservo.write(pos);
        for (int i=0; i<=10; i+=1)
        {   
           median_volt = median_volt + analogRead(A0)* (5.0 / 1023.0);
           delay (100);
           //Serial.println(median_volt);
        }
      //median_volt = median_volt/10;
      Serial.print(median_volt/10); 
      Serial.print(' ');  
      Serial.print((ang/180)*3.14*16.5);
      Serial.println("cm");
      ang = ang + 1;           
      delay(1000);                   
    }
    delay(1000);
    myservo.write(0);
    delay(1000);
    exit(0);
  }
  
  //for (pos = 0; pos <= 1; pos += 1) 
  //{ 
    // in steps of 1 degree
  //  myservo.write(pos);              
  //  delay(1000);                   
  //} 
}
