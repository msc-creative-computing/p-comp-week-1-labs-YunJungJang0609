const int pingPin = 3; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 4; // Echo Pin of Ultrasonic Sensor

int led = 9;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
}

void loop() {
  pinMode(led, OUTPUT);
  
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   //Serial.print(inches);
   //Serial.print("in, ");
   Serial.print(cm);
   //Serial.print("cm");
   //Serial.println();


  int fadeAmount = cm/5;
  //Serial.println(fadeAmount);

Serial.println(fadeAmount);
  // set the brightness of pin 9:
  analogWrite(led, fadeAmount);
   
   delay(100);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
