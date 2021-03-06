#define echoPin 11 // Echo Pin
#define trigPin 12 // Trigger Pin

long distance;
long duration;
void setup(){
  
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
}

void loop(){
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = duration/58.2;


//to Processing via serial communication
Serial.write(distance);
delay(100);
}
