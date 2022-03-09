int sensorPin = A0;    // select the input pin for the potentiometer
int pinPWM = 6;
int sensorValue=0;
bool sentido= false;
float contador=0;

void contar(){
contador = contador + 1;
Serial.print("Distance ");
Serial.print(contador/2);
Serial.println(" cm");
}

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(3, INPUT_PULLUP); 
  Serial.begin(9600);
  attachInterrupt(0,contar,FALLING);
  attachInterrupt(1,iniciar,FALLING);
}

void loop() {
 sensorValue = analogRead(sensorPin);   
}

void iniciar(){
  if (sentido==true){
  contador=0;
  Serial.println("Motor on");
  analogWrite(pinPWM,220);
  sentido=false;
  }
  else{
    Serial.println("Motor off");
    digitalWrite(pinPWM,LOW);
    sentido=true;
    contador=0;
    }
}

