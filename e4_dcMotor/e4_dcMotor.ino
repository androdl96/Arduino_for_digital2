/*
*1 DC motor
*1 Motor driver L293D
*1 Photoresistance
*1 External power supply
*/

#define speedPin 6
#define dirPin1 7
#define dirPin2 5

int speedMotor = 180;


void setup() {
  pinMode(speedPin,OUTPUT);
  pinMode(dirPin1,OUTPUT);
  pinMode(dirPin2,OUTPUT);
  
  Serial.begin(9600);
  digitalWrite(dirPin1,0);
  digitalWrite(dirPin2,1);
  analogWrite(speedPin, speedMotor);
}

void loop() {
  speedMotor=analogRead(A0)/4;
  Serial.println(analogRead(A0));
  analogWrite(speedPin, speedMotor);
}
