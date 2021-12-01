/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>
#include <LiquidCrystal.h>

#define UPDATES_PER_SECOND 100

Servo doorServo;  // create servo object to control a servo
Servo buttonServo;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int openButton = 9;

int buttonState = 0;
int floorData;
int floorSensor = A0;
int topSensor = A1;
int pos = 0;    // variable to store the servo position

byte heart[8] = {
  0b00000,
  0b01010,
  0b11111,
  0b11111,
  0b01110,
  0b00100,
  0b00000,
  0b00000
};

byte arrowDown[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b11111,
  0b01110,
  0b00100
};

byte arrowRight1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

byte arrowRight2[8] = {
  0b10000,
  0b11000,
  0b11100,
  0b11110,
  0b11100,
  0b11000,
  0b10000,
  0b00000
};




void setup() {

  //Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  pinMode (openButton, INPUT);
  pinMode(floorSensor, INPUT);
  pinMode(topSensor, INPUT);
  
  doorServo.attach(13);  // attaches the servo on pin 13 to the servo object
  buttonServo.attach(10);

  
  //set all servo angles to 0
  doorServo.write(0); 
  buttonServo.write(0);

  floorData = 100;

  //create special characters in lcd
  lcd.createChar(0, heart);
  lcd.createChar(1, arrowDown);
  lcd.createChar(2, arrowRight1);
  lcd.createChar(3, arrowRight2);
  
}

void loop() {

  buttonState = digitalRead(openButton);
  //Serial.println(buttonState);

  floorData = analogRead(floorSensor);

  floorData = map(floorData, 600, 880, 0, 100); //setting floor value from 0 to 100

Serial.println(floorData);
  
if(floorData >=50){
  //write in lcd
  lcd.setCursor(0, 0);
  lcd.write((byte)0);
  // Print a message to the LCD.
  lcd.print("Insert coins");
  lcd.write((byte)0);
  // set the cursor to column 0, line 1
  lcd.setCursor(0, 1);
  lcd.write((byte)1);
  lcd.print("Open moneybank");
  lcd.write((byte)1);
}


  //when the amount is reached
  else if(floorData <50){
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.write((byte)0);
    lcd.print("Insert coins");
    lcd.write((byte)0);
    lcd.setCursor(0, 1);
    lcd.print("Open moneybank");
    lcd.write((byte)2);
    lcd.write((byte)3);
    
    buttonServo.write(180);              
    
  }
    
 




//if the open button is pressed, open the door
  if(buttonState == HIGH){

      buttonServo.write(0);
      
    
  //for (pos = 0; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree
    doorServo.write(110);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}
  delay(10000);
  //for (pos = 110; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    doorServo.write(0);              // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  //}

  }
}
