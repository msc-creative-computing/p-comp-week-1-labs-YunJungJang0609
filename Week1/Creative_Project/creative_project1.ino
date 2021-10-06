// C++ code
//

const int sensorPin = A0;
const float baselineTemp = -500;
int score = 0;
bool once = false;


int switchstatement = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
}

void loop()
{
  //calculate the body temperature
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperature = (voltage - 5) * 100;
  
  //game is over
  if(score == 5){
    gameFinished();
  }
  
  
  //depends on the temperature, set the levels of the game
  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    isAlienTrue();
  }
  
  else {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    isAlienFalse();
  }
  
}




void isAlienTrue(){
  
  //Generate random number between 4 and 9
  int ranNum = random(4,9);
  int switchNum = ranNum+5;
  
  for(int i=0; i<500; i++){
    
  	digitalWrite(ranNum, HIGH);
    switchstatement = digitalRead(switchNum);
    
    if(switchstatement == 1 && once == false) {
      	once = true;
    	score++;
    	Serial.print("The score is: ");
    	Serial.print(score); 
    	Serial.println(""); 
  	}
  }
  
    
  digitalWrite(ranNum, LOW);
  delay(250);
  once = false;
}

void isAlienFalse(){
  
  //Generate random number between 4 and 9
  int ranNum = random(4,9);
  int switchNum = ranNum+5;
  
  
  for(int i=0; i<5000; i++){
    
  	digitalWrite(ranNum, HIGH);
    switchstatement = digitalRead(switchNum);
    
    if(switchstatement == 1 && once == false) {
      	once = true; //button pressed only once
    	score++;
    	Serial.print("The score is: ");
    	Serial.print(score); 
    	Serial.println(""); 
  	}
  }
  
  digitalWrite(ranNum, LOW);
  delay(200);
  once = false; //reset button press
  
  
}


void gameFinished(){
  Serial.println("Well done! System loading...");
}