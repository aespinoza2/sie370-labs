/*
Program: 2-wire LCD
Name: Agustin Espinoza
Course: SIE 370
Professor: Dr. Keaton
*/

#include <LiquidCrystal.h>

// Pin definitions for LCD
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

// Pin definitions for RGB LED
const int redPin = 6, bluePin = 5, greenPin = 3;

// Pin definitions for button
const int buttonPin = 2;

// Global variables
volatile boolean stopFlag = false;
int zone1Duration = 0;
int zone2Duration = 0;

// Initialize LCD object with the above pin numbers
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set RGB LED pins to OUTPUT mode
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  // Set button pin to INPUT mode
  pinMode(buttonPin, INPUT);

  // Initialize the LCD
  lcd.begin(16, 2);

  // Set RGB LED to red in Wait Mode
  digitalWrite(redPin, HIGH);
  digitalWrite(bluePin, LOW);
  digitalWrite(greenPin, LOW);

  // Clear the LCD screen
  lcd.clear();

  // Print the message to the LCD screen
  lcd.setCursor(0,0);
  lcd.print("Enter Duration");

  // Print the message to the Serial Monitor
  Serial.begin(9600);
  Serial.println("Please enter the time setting for the zones (in seconds).");

  // Wait for the user input
  while (!Serial.available()) {}

  // Get user input from Serial Monitor
  zone1Duration = Serial.parseInt();

  // Check validity of user input
  if (zone1Duration < 1 || zone1Duration > 10) {
    // Display error message on Serial Monitor
    Serial.println("Error: Invalid Entry!");

    // Clear the LCD screen
    lcd.clear();

    // Print the message to the LCD screen
    lcd.setCursor(0,0);
    lcd.print("Error: Invalid");

    lcd.setCursor(0,1);
    lcd.print("Entry! Re-enter");

    // Wait for 5 seconds before proceeding to Wait Mode
    delay(5000);

    // Return to Wait Mode
    setup();
  }

  // Set RGB LED to green in Run Mode
  digitalWrite(redPin, LOW);
  digitalWrite(greenPin, HIGH);

}

void loop() {
  // Check if button is pressed
  if (digitalRead(buttonPin) == HIGH) {
    // Set stopFlag to true to return to Wait Mode
    stopFlag = true;
  }

  // Check if stopFlag is true
  if (stopFlag == true) {
    // Reset stopFlag to false
    stopFlag = false;

    // Return to Wait Mode
    setup();
  }

  // Zone 1
  digitalWrite(bluePin, LOW);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Zone 1");

  // Irrigate zone 1 for the specified duration
  for (int i = 0; i < zone1Duration; i++) {
    digitalWrite(bluePin, LOW);
 	  lcd.clear();
  	lcd.setCursor(0,0);
  	lcd.print("Zone 1");
    delay(zone1Duration*1000);
    
    digitalWrite(bluePin, LOW);
 	  lcd.clear();
  	lcd.setCursor(0,0);
    lcd.print("Zone 2");
    delay(zone1Duration*1000);
    
    // Check if button is pressed
  	if (digitalRead(buttonPin) == HIGH) {
      // Set stopFlag to true to return to Wait Mode
      stopFlag = true;
      break;
    }
  }

  
  // Check if stopFlag is true
  if (stopFlag == true) {
    // Reset stopFlag to false
    stopFlag = false;

    // Return to Wait Mode
    setup();
  }
}