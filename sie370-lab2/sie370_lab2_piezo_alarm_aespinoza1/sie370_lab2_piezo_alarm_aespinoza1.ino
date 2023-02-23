// declare constants that don't change
int 	buzzer =8;	// pin for our buzzer output
int 	pushButton = 3; // pin for our push button input
int 	alarmLED = 9;	// pin of our alarm LED

// declare our variables that change

float 	valSIN;		// value of our SIN wave
int 	valTone;	// value for our tone
int 	valButton;	// value for our push button
bool 	bAlarm; 	// current state of the Alarm (On = True, Off = False)
int 	buttonState;             // the current reading from the input pin
int 	lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

// configure our input and output
void setup() 
{
  Serial.begin(9600);  
  pinMode(alarmLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(pushButton, INPUT);

  // set initial state of alarm LED
  digitalWrite(alarmLED, LOW);
}

// process our solution
void loop() 
{
  valButton = debounce(lastButtonState);   //Read debounced state  // read the value from 
  Serial.println(valButton);

  if ((lastButtonState == LOW) && (valButton == HIGH)) //if it was pressed…
  {
    if (bAlarm == true) 
      shutOffAlarm();  	// shut off the alarm 
    else
      activateAlarm();  // activate the alarm
  }
  
  lastButtonState = valButton;                                      //Reset button value
}

/****
* Debouncing Function 
* Author: Jeremy Blum, Exploring Arduino textbook, Chapter 2
* Modified: Sherilyn Keaton
* Pass it the previous button state, and get back the current debounced button state.
*****/
boolean debounce(boolean lastState)
{
 boolean currentState = digitalRead(pushButton);   // Read the button state
 if (lastState != currentState)                     // if it's different…
 {
  delay(5);                               //Wait 5ms 
  currentState = digitalRead(pushButton);          //Read it again
 }
 return currentState;     //Return the current value
}

// activate the alarm
void activateAlarm()
{
  bAlarm = true; 
  digitalWrite(alarmLED, HIGH);

  for (int x=0; x<180; x++) 
  {
    // convert degrees to radians then obtain sin value
     valSIN = (sin(x*(3.1412/180)));
     // generate a frequency from the sin value
     valTone = 200+(int(valSIN*1000));
     tone(8, valTone);
     delay(2);
  } 
}
  
// shut off the alarm
void shutOffAlarm()
{
  bAlarm = false; 				// set the Alarm boolean flag, bAlarm, to false
  digitalWrite(alarmLED, LOW);	// turn the alarmLED off
  noTone(8);  					// use the Arduino function noTone() to turn the alarm sound off in the buzzer

}

  