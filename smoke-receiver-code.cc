
//Arduino Code – For Receiver(receiver code for smoke detector sensor (MQ-gas-sensor))

// To understand How nRF24l01 (teansceiver) interface with arduino this is the link [https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/].
//this link shows how to download RF24 Arduino Library for nRF24L01.
//The sketch starts by including the libraries. SPI.h library handles the SPI communication while nRF24L01.h and RF24.h controls the module.


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);                              //At the end we just print the received message on serial monitor.
  }
}