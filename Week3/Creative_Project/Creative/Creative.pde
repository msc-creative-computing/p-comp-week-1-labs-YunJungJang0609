import processing.serial.*;

Serial myPort;
int x, y; 


Mountain mountain = new Mountain();
Moon moon;
int prevDist=0, distance = 0;
int handY;

class Moon{
  int x, y;
  int size;
  float speed;
  float acceleration;
  
  Moon(){
   x = width/4;
   y = height/2;
   size = 40;
   speed = 0;
  }
  

  void control(){

    y = handY;
    
  }
    
    //to draw a jumping circle
  void display(){
    pushMatrix(); //move the screen
    translate(x, y); //the transformation is reset when the loop begins again. Further controlled by using pushMatrix()
    fill(255, 191, 0); //colour of the moon
    circle(0, size, size);  
    noStroke();
    popMatrix(); //Pops the current transformation matrix off the matrix stack
  }
  
}


class Mountain{
  int mountainWidth;
  int upperBound;
  int lowerBound; //lower pipe passable coordinate y
  int mountainX;//location x of the pipe
  
  Mountain() {
    mountainWidth = 80; 
  }
  
  void update(){ 
    mountainX -= 2;
    if (mountainX+mountainWidth<0) {
      renew();
     }
  }
  
  void renew(){
    mountainX = width;
    upperBound = int(random(20, height-130));
    lowerBound = upperBound+110;
  }
  
  
  void display(){
    stroke(0);
    fill(0, 255, 0);
    arc(mountainX, lowerBound, 280, height, PI, TWO_PI);
    noStroke();
  }
  
}


void setup() {
  size(300, 500);
  moon = new Moon();
  mountain.renew();
  myPort = new Serial(this,Serial.list()[0], 9600);
}



void draw() {
  background(0); //canvas

  mountain.update();
  moon.control();
  
  moon.display();
  mountain.display();
  
}

void serialEvent(Serial p)
{
distance = myPort.read();
handY = int(map(distance, 0, 20, 0, height)); //Re-maps a number from one range to another: map distance to 0…height
myPort.clear();
}
