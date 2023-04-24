/*
Program: Monitoring and Data Logging System
Name: Agusting Espinoza
Course: SIE 370 - Embedded Computer Systems
Professor: Dr. Keaton
Date: 4/19/23

Reference:
LCD Thermometer using TMP36 Sensor
https://projecthub.arduino.cc/VJZ/f08c134a-04f6-460d-b697-9051ca02cbc4

Ping Ultrasonic Range Finder
https://docs.arduino.cc/built-in-examples/sensors/Ping

Piezzo Buzzer
https://www.instructables.com/How-to-use-a-Buzzer-Arduino-Tutorial/
*/

#include <LiquidCrystal.h>

import processing.serial.*;
Serial mySerial;
PrintWriter output;

// Define LCD pin connections
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Define analogue sensor pin connection
int sensorPin = 0; 

// Define piezzo buzzer pin connection
const int buzzer = 8;

// DISTANCE SENSOR
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long duration;
int distance;

void setup(){
  // Initialize LCD display
  lcd.begin(16, 2);
  // Initialize serial port at 9600 baud rate
  Serial.begin(9600);
  // Initialze buzzer
  pinMode(buzzer, OUTPUT);

  // DISTANCE SENSOR

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  mySerial = new Serial( this, Serial.list()[0], 9600 );
  output = createWriter("output.txt");
}
  
void loop(){
  // TEMP SENSOR 
  
  // Clear CLD
  lcd.clear();
  // Define reading var
  int reading =  analogRead(sensorPin);
  // Define voltage var
  float voltage = reading * 5.0;
  // Set voltage constraint
  voltage /= 1024.0;  
  // Define Celsius temperature var 
  float temperatureC = (voltage - 0.5) * 100 ; 
  // Define Fahreinheit temperature var
  float temperatureF = (temperatureC  * 9.0 / 5.0) + 32.0;
 
  // Print Fahreinheit temp reading to LCD 
  lcd.print(temperatureF); 
  // Print temperature units (F)
  lcd.println(" degrees F ");
  // Set cursor to next line
  lcd.setCursor(0,1);
  // Print Celsius temp reading to LCD
  lcd.print(temperatureC);
  // Print temp units (C)
  lcd.println("  degrees C ");
  // Wait 1 second
  delay(1000);
  


  // DISTANCE SENSOR 
  
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  double duration, inches, cm;

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" CM");
  Serial.print("\t");

  // convert the time into a distance
  // inches = microsecondsToInches(duration);
  // cm = microsecondsToCentimeters(duration);	
  
  if (distance <= 6){
    tone(buzzer, 440);
    delay(100);
    noTone(buzzer);
    delay(100);
  }
  
  // Serial.print(inches);
  // Serial.print("in, ");
  // Serial.print(cm);
  // Serial.print("cm");
  // Serial.println();
  // Serial.println(duration);

  //TEST temp
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C");
  Serial.print("\t");
  
  delay(1000);
}


void draw() {
    if (mySerial.available() > 0 ) {
         String value = mySerial.readString();
         if ( value != null ) {
              output.println( value );
         }
    }
}

void keyPressed() {
    output.flush();  // Writes the remaining data to the file
    output.close();  // Finishes the file
    exit();  // Stops the program
}