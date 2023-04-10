/*
Program: Theremin Data Logger System
Name: Agustin Espinoza
Course: SIE 370 - Embedded Computer Systems
Professor: Dr. Keaton
Date: 4/5/23

Ref:
Photoconductive Cells Datasheet
https://cdn.sparkfun.com/datasheets/Sensors/LightImaging/SEN-09088.pdf

Autodesk Digital Light Theremin Project
https://www.instructables.com/Digital-Light-Theremin/

Additional Reading for Photoresistors
https://eepower.com/resistor-guide/resistor-types/photo-resistor/#
*/


int photopin = 0; // Pin where the photo resistor is connected to
int photValue; // The analog reading from the photoresistor
int buzzerPin = 8; // Connect Buzzer to Pin 8
long buzzerFreq; // The frequency to buzz the buzzer

// You can experiment with these values:
long buzzMAX = 2500; // Maximum frequency for the buzzer
long photoMAX = 1023; // Maximum value for the photoresistor

void setup(){
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT); // set a pin for buzzer output
}

void loop() {
  // read the values of the potentiometer
  photValue = analogRead(photopin); // Values 0-1023
  // normalize the readings of a photoresistor to thatof the buzzer and photoresistor
  buzzerFreq = (photValue * buzzMAX) / photoMAX;
  Serial.println(buzzerFreq);
  buzz(buzzerPin, buzzerFreq, 10);
}

void buzz(int targetPin, long frequency, long length) {
  long delayValue = 1000000/frequency/2;
  long numCycles = frequency * length/ 1000;
  
  for (long i=0; i < numCycles; i++) {
    digitalWrite(targetPin,HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin,LOW);
    delayMicroseconds(delayValue);
  }
}