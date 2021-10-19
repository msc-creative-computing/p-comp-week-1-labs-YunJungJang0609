//base code from here: https://create.arduino.cc/projecthub/Mako_/arduino-sunflower-c4fd84?ref=tag&ref_id=servo&offset=0

#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

int led1 = 3;
int led2 = 4;
int timeCount = 0;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 40;

int period = 5000;
unsigned long time_now = 0;

Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( servoGrad );

  pinMode(led1, OUTPUT );
  pinMode(led2, OUTPUT );
}

void loop() {
    
  sensorValue = analogRead(sensorPin);
  

  if(timeCount<1001){
    
        timeCount++;
        digitalWrite(led1, HIGH);   
        digitalWrite(led2, LOW);
        Serial.println(timeCount);
  }

  else if (timeCount>=1001 && timeCount < 2000){
      
        timeCount++;
        digitalWrite(led1, LOW); 
        digitalWrite(led2, HIGH); 
        Serial.println(timeCount);
  }
  
  if ( sensorValue < (512-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (512+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad ); 

  if(timeCount >=2000){
    timeCount = 0;
  }
  
}
