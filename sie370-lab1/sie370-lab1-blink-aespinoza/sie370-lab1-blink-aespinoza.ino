/*
Program: Blink
Author: Agustin Espinoza
Course: SIE370
Professor: Dr. Keaton
Date: 2/1/23

Ref: https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

// setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(13, HIGH);
  // wait for 1000 ms = 1 s  
  delay(1000);
  // turn the LED off by setting voltage to LOW
  digitalWrite(13, LOW);
  // wait for 1000 ms = 1 s
  delay(1000);
}