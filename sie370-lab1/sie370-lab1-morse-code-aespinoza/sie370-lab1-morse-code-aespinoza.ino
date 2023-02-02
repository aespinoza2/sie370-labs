/*
Program: Morse Code
Author: Agustin Espinoza
Course: SIE370
Professor: Dr. Keaton
Date: 2/1/23

Instructions:
Using the rules and values in the Morse Code Chart below, write out the international distress message 
SOS (letter S, letter O, letter S from the chart below) with the following rules:
(a) A Unit is 100 ms, so
(b) Dot gets 100 ms
(c) Dash gets 300 ms
(d) Between each part of the same letter is 100 ms
(e) Between each letter is 300 ms
(f) Between each SOS is 700 ms

Hint: program it so that each pass through the loop() function spells out SOS
*/

void setup() {
  // initialize digital pin 13 as output
  pinMode(13, OUTPUT);
}

void loop() {
  /*
  Letter S (three dots):
  - dot 1
    - Turn ON for 100 ms (Dot gets 100 ms)
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dot 2
    - Turn ON for 100 ms ((Dot gets 100 ms))
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dot 3
    - Turn ON for 100 ms (Dot gets 100 ms)
    - Turn OFF for 300 ms (SPACE between each letter is 300 ms)
  */
  // dot 1 ON
  digitalWrite(13, HIGH);
  delay(100);
  // dot 1 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dot 2 ON
  digitalWrite(13, HIGH);
  delay(100);
  // dot 2 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dot 3 ON
  digitalWrite(13, HIGH);
  delay(100);
  // SPACE before next letter
  digitalWrite(13, LOW);
  delay(300);
  /*
  Letter S (three dots):
  - dash 1
    - Turn ON for 300 ms (Dash gets 300 ms)
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dash 2
    - Turn ON for 300 ms ((Dash gets 300 ms))
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dash 3
    - Turn ON for 300 ms (Dash gets 300 ms)
    - Turn OFF for 300 ms (SPACE between each letter is 300 ms)
  */
  // dash 1 ON
  digitalWrite(13, HIGH);
  delay(300);
  // dash 2 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dash 2 ON
  digitalWrite(13, HIGH);
  delay(300);
  //dash 2 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dash 3 ON
  digitalWrite(13, HIGH);
  delay(300);
  // SPACE before next letter
  digitalWrite(13, LOW);
  delay(300);  
  /*
  Letter S (three dots):
  - dot 1
    - Turn ON for 100 ms (Dot gets 100 ms)
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dot 2
    - Turn ON for 100 ms ((Dot gets 100 ms))
    - Turn OFF for 100 ms (Between each part of the same letter is 100 ms)
  - dot 3
    - Turn ON for 100 ms (Dot gets 100 ms)
    - Turn OFF for 700 ms (Between each SOS is 700 ms)
  */
  // dot 1 ON
  digitalWrite(13, HIGH);
  delay(100);
  // dot 1 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dot 2 ON
  digitalWrite(13, HIGH);
  delay(100);
  // dot 2 OFF
  digitalWrite(13, LOW);
  delay(100);
  // dot 3 ON
  digitalWrite(13, HIGH);
  delay(100);
  // Between each SOS is 700 ms
  digitalWrite(13, LOW);
  delay(700);
}
