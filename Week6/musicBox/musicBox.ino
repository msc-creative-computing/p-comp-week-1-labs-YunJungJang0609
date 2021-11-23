#include "musicBox.h" //this is for our tones and is for reference. 
#include <Wire.h>

#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493


int thumb = A0;//analog pin for the sensor 
int index = A1;
int middle = A2; 

int buzzer = 11;

int btn = 12; //pin for the button 

void setup() {
Serial.begin(9600); //start printing out to the serial port for processing to read from

pinMode(thumb, INPUT);//add a input for your potentiometer 
pinMode(index, INPUT);
pinMode(middle, INPUT);   

pinMode(btn, INPUT_PULLUP);//add an input for the button. We're using input pull up because otherwise, there'd be a short
//you can also do this in hardware. I often do. See pull up resistor  
}

void loop() {
	
  int thumbData = analogRead(thumb);//take an analog read on the knob to read resistance(0 to 1024)
  int indexData = analogRead(index);
  int middleData = analogRead(middle); 
  
	int btnState = digitalRead(btn); //digitally read the button (0 or 1) 
	//Serial.println(btnState); //optional print line for testing 

  
thumbData = map(thumbData, 0, 1024, 0, 1000);
indexData = map(indexData, 0, 1024, 0, 500);
middleData = map(middleData, 0, 1024, 100, 700);//using the map function, transform the range of the 
//tone that the resistor is in, 0 to 1024 to the range of tones we want to play. 

	if(btnState==1) // the button is pushed down 
	{
		//int pauseBetweenNotes = 2 * 1.30;//make a little pause to not overwhelm arduino
		tone(buzzer, middleData, thumbData-indexData);
    delay(middleData);
		//delay(pauseBetweenNotes); // a little pause 
		Serial.println(middleData); // print it out 
		noTone(buzzer);//turn off the pad  
	}else{ //the button is not pushed 
		noTone(buzzer); //make no noise  
	}
}
