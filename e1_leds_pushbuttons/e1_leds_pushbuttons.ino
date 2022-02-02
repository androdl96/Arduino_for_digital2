/*
 - 2 push buttons (connected to pins 2 and 4)
 - 2 leds (connected to pins 10 and 12)
 - 2 220 ohms resistors
*/
void blink();

byte button1=4;
byte button2=2;
byte led1=12;
byte led2=10;

void setup(){
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
  pinMode(led2, OUTPUT);
  digitalWrite(led2, LOW);
  
  attachInterrupt(0, blink, FALLING);
}

void loop(){
  if (digitalRead(button1)==0){
    digitalWrite(led1, !digitalRead(led1));
    }
    delay(3000);
}

void blink(){
  digitalWrite(led2, !digitalRead(led2));
}
