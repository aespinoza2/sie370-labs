/*
Program: PWM
Author: Agustin Espinoza
Course: SIE370
Professor: Dr. Keaton
Date: 2/1/23

Instructions:
Write the code that will control two LEDs such that:
  (a.) LED 1 will slowly increase brightness from 0% to 100%
  (b.) LED 2 will slowly (at the same rate as LED 1), decrease brightness from 100% to 0%

HINT: In the Fade tutorial, we used a For Loop. Here, we will rely on our loop () function to set and reset the
brightness for LED 1 and LED 2. When we have faded the LEDs from one extreme value to the other, we reset
the brightness values for each

Ref: https://docs.arduino.cc/built-in-examples/basics/Fade
*/

// LED 1 is attached to PWM pin 3
int led1 = 3;
// LED 2 is attached to PWM pin 11
int led2 = 11;
// Initial LED 1 brightness
int led1Brightness = 0;
// Initial LED 2 brightness
int led2Brightness = 100;
// the points to fade the LED by
int fadeAmount = 5;

// setup function runs once when you press reset
void setup() {
  // declare led1 (pin 3) to be an output:
  pinMode(led1, OUTPUT);
  // declare led2 (pin 11) to be an output:
  pinMode(led2, OUTPUT);
}

// loop function continues forever
void loop() {
  // set the brightness of led1
  analogWrite(led1, led1Brightness);
  // set the brightness of led2
  analogWrite(led2, led2Brightness);
  // change the brightness for LED 1 next time through the loop
  led1Brightness = led1Brightness + fadeAmount;
  // change the brightness for LED 2 next time through the loop
  led2Brightness = led2Brightness - fadeAmount;

  // reverse the direction of the fading at the ends of the fade
  if (led1Brightness <= 0 || led1Brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  if (led2Brightness <= 0 || led2Brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}