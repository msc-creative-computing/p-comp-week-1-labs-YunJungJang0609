// Sketch: Blinking two LEDs by user
int ledPin = 10; // declare pin10 as ledpin
int numBlinks; // variable to store the number of blinks
String LedOnMessage = "Red LED is turned on"; // this is a string with information
String LedOffMessage = "Red LEd is turned off"; // this is a string with information
void setup()
{
  pinMode(ledPin, OUTPUT);  // set pin10 as output pin
  digitalWrite(ledPin, LOW); // set the pin value on low at the begin
  Serial.begin(9600);
}
void loop()
{
  Serial.println("How Many Times Do You Want the Red LEDs to blink?"); //Prompt User for Input
  while (Serial.available() == 0) {
    // Wait for User to Input Data
  }
  numBlinks = Serial.parseInt(); //Read the data the user has input
  for (int counter = 1; counter <= numBlinks; counter++) {
    Serial.println(LedOnMessage);
    digitalWrite(ledPin, HIGH);
    delay(1000);
    Serial.println(LedOffMessage);
    digitalWrite(ledPin, LOW);
    delay(1000);
  }
  Serial.print("The user has choosen the number:");
  Serial.println(numBlinks);
  Serial.println(" ");
}
