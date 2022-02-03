/*
*1 IR sensor
*1 Ultrasonic sensor HC-SR04
*1 LCD Screen 16x2
*1 Potentiometer
*/

#include <LiquidCrystal.h>

#define trigPin 13
#define echoPin 12
int duration,distance;
LiquidCrystal lcd(6,7,8,9,10,11);

void measure();

void setup() {
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  attachInterrupt(0, measure, RISING);
  //Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Distance :");
}

void loop() {
}

void measure(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration/2) / 29.1);
  //Serial.print(distance);
  //Serial.println(" cm");

  lcd.setCursor(0,1);
  lcd.print("        ");
  lcd.setCursor(2,1);
  lcd.print(distance);
  lcd.print(" cm");
  }
