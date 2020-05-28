//The SoftwareSerial library has been developed to allow serial communication on other digital pins of the Arduino,using software to replicate the funcationality (hence the name "SoftwareSerial"). 



#include<SoftwareSerial.h>
int Led = 12;
int smokeA0 = A5;
                         
int sensorThres = 400;               // Your threshold value

void setup() {
  pinMode(Led, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  
  if (analogSensor > sensorThres)       // Checks if it has reached the threshold value
  {
    digitalWrite(Led, HIGH);
    
  }
  else
  {
    digitalWrite(Led, LOW);
  }
  delay(100);
}