/*
 *1 4 seven segment display common cathode
 *1 74HC595N or equivalent
 *4 220 ohm resistors
 *1 1k ohm resistor
 *1 photoresistor
 *1 potentiometer
 */

#define LATCH 3      //74HC595  pin 9 STCP
#define CLK 4        //74HC595  pin 10 SHCP
#define DATA_PIN 2   //74HC595  pin 8 DS

#define L1000 8  //Lamp in 1000 position
#define L0100 9  //Lamp in 0100 position
#define L0010 10 //Lamp in 0010 position
#define L0001 11 //Lamp in 0001 position
int delay_value=2;
int sensor_val;

unsigned char table[]=
{0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c
,0x39,0x5e,0x79,0x71,0x00};

void Display(unsigned char);
void Print_num(unsigned char,unsigned char,unsigned char,unsigned char);

void setup() {
  pinMode(LATCH,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);

  pinMode(8,OUTPUT);
  digitalWrite(8,HIGH);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
}

void loop() {
  sensor_val=analogRead(A5);
  Print_num(sensor_val/1000,(sensor_val%1000)/100,(sensor_val%100)/10,sensor_val%10);
}

void Display(unsigned char num)
{
  digitalWrite(LATCH,LOW);
  shiftOut(DATA_PIN,CLK,MSBFIRST,table[num]);
  digitalWrite(LATCH,HIGH);
}

void Print_num(unsigned char n1,unsigned char n2,unsigned char n3,unsigned char n4){
  digitalWrite(L1000,LOW);
  digitalWrite(L0100,HIGH);
  digitalWrite(L0010,HIGH);
  digitalWrite(11,HIGH);
  Display(n1);
  delay(delay_value);
  digitalWrite(L1000,HIGH);
  digitalWrite(L0100,LOW);
  digitalWrite(L0010,HIGH);
  digitalWrite(L0001,HIGH);;
  Display(n2);
  delay(delay_value);
  digitalWrite(L1000,HIGH);
  digitalWrite(L0100,HIGH);
  digitalWrite(L0010,LOW);
  digitalWrite(L0001,HIGH);;
  Display(n3);
  delay(delay_value);
  digitalWrite(L1000,HIGH);
  digitalWrite(L0100,HIGH);
  digitalWrite(L0010,HIGH);
  digitalWrite(L0001,LOW);;
  Display(n4);
  delay(delay_value);
  }
