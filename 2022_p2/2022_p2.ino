#include <IRremote.h>
#include <Stepper.h>

int RECV_PIN = 8;
int bluePin = 9;
int greenPin = 10;
int redPin = 11;
double stepsPerRevolution = 2048;
int step1 = 1040;
Stepper myStepper(stepsPerRevolution,6,4,5,3);
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup(){
  myStepper.setSpeed(10);
  irrecv.enableIRIn();
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop(){
  if (irrecv.decode(&results)){
  int value = results.value;
  switch (value){
    case 12495: // Keypad button "1"
    analogWrite(redPin,0xFF);
    analogWrite(greenPin,0xFF);
    analogWrite(bluePin,0xFF);
    break;
    
    case 6375: // Keypad button "2"
    analogWrite(redPin,0x00);
    analogWrite(greenPin,0x00);
    analogWrite(bluePin, 0xFF);
    break;
    
    case 31365: // Keypad button "3"
    analogWrite(redPin,0xFF);
    analogWrite(greenPin,0x00);
    analogWrite(bluePin,0x00);
    break;
    
    case 4335: // Keypad button "4"
    analogWrite(redPin,0x00);
    analogWrite(greenPin,0xFF);
    analogWrite(bluePin,0x00);
    break;
    
    case -15811:
    myStepper.step(-step1);
    delay(1000);
    break;
  
    case 8925:
    myStepper.step(step1);
    delay(1000);
    break;
    
    case -28561:
    myStepper.step(-500);
    delay(1000);
    break;
    
    case -8161:
    myStepper.step(500);
    delay (1000) ;
    break;
    
    default:
    int qqq=0;
    }
  irrecv.resume();
  } 
}
