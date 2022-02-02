#define trigPin 13
#define echoPin 12
int duration,distance;

void measure();

void setup() {
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin,LOW);
  attachInterrupt(0, measure, RISING);
  Serial.begin(9600);
}

void loop() {
}

void measure(){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((duration/2) / 29.1);
  Serial.print(distance);
  Serial.println(" cm");
  }
