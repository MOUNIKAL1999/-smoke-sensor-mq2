
//Arduino Code – For Transmitter(transmiter code for smoke detector sensor (MQ-gas-sensor))

// To understand How nRF24l01 (teansceiver) interface with arduino this is the link [https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/].
//this link shows how to download RF24 Arduino Library for nRF24L01.
//The sketch starts by including the libraries. SPI.h library handles the SPI communication while nRF24L01.h and RF24.h controls the module.


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include<SoftwareSerial.h>

int Led = 12;
int smokeA0 = A5;        
int sensorThres = 400;  

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN


const byte address[6] = "00001";     //address through which two modules communicate.

void setup()
{
  radio.begin();
  pinMode(Led, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  
  if (analogSensor > sensorThres)       // Checks if it has reached the threshold value
  {
    digitalWrite(Led, HIGH);
  //Send message to receiver
  const char text[] = "Smoke detected";
  radio.write(&text, sizeof(text));
   }
  else
  {
    digitalWrite(Led, LOW);
  }
  
  delay(1000);
}