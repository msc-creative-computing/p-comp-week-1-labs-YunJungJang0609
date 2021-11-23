int red_light_pin= 11;
int green_light_pin = 10;
int blue_light_pin = 9;

int sensor1 = A0;
int sensor2 = A1;
int sensor3 = A2;

void setup() {

  Serial.begin(9600);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  
  pinMode(red_light_pin, OUTPUT);
  pinMode(green_light_pin, OUTPUT);
  pinMode(blue_light_pin, OUTPUT);
}
void loop() {

int sensorValue1 = analogRead(sensor1);
int sensorValue2 = analogRead(sensor2);
int sensorValue3 = analogRead(sensor3);

sensorValue1 = map(sensorValue1, 0, 25, 0, 255);
sensorValue2 = map(sensorValue2, 0, 25, 0, 255);
sensorValue3 = map(sensorValue3, 0, 25, 0, 255);

RGB_color(sensorValue1, sensorValue2, sensorValue3);

Serial.println(sensorValue1);
Serial.println(sensorValue2);
Serial.println(sensorValue3);
Serial.println();

delay(100);


  
//  RGB_color(255, 0, 0); // Red
//  delay(1000);
//  RGB_color(0, 255, 0); // Green
//  delay(1000);
//  RGB_color(0, 0, 255); // Blue
//  delay(1000);
//  RGB_color(255, 255, 125); // Raspberry
//  delay(1000);
//  RGB_color(0, 255, 255); // Cyan
//  delay(1000);
//  RGB_color(255, 0, 255); // Magenta
//  delay(1000);
//  RGB_color(255, 255, 0); // Yellow
//  delay(1000);
//  RGB_color(255, 255, 255); // White
//  delay(1000);
}
void RGB_color(int red_light_value, int green_light_value, int blue_light_value)
 {
  analogWrite(red_light_pin, red_light_value);
  analogWrite(green_light_pin, green_light_value);
  analogWrite(blue_light_pin, blue_light_value);
}
