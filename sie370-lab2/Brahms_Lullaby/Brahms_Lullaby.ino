
#include"pitches.h"

// notes in the song 'Mukkathe Penne'
int melody[] = {
  NOTE_E4,NOTE_E4,NOTE_G4,NOTE_E4,NOTE_E4,NOTE_G4,
  NOTE_E4,NOTE_G4,NOTE_C5,NOTE_B4,NOTE_A4,NOTE_A4,
  NOTE_G4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_D4,NOTE_D4,NOTE_E4,
  
  NOTE_F4,NOTE_D4,NOTE_F4,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_B4,NOTE_C5,NOTE_C4,NOTE_C4,
  NOTE_C5,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_E4,NOTE_C4,NOTE_F4,NOTE_G4,NOTE_A4,
  NOTE_G4,NOTE_C4,NOTE_C4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_G4,NOTE_E4,NOTE_C4,
  NOTE_F4,NOTE_E4,NOTE_D4,NOTE_C4,
  
  END,
};

// note durations: 8 = quarter note, 4 = 8th note, etc.
int noteDurations[] = {       //duration of the notes
  4, 4, 8, 4, 4, 8,
  2, 2, 4, 4, 4, 2, 
  2, 2, 2, 4, 4, 2, 2,

  8,2,2,2,2,4,4,8,2,2,
  8,2,2,8,2,2,4,4,4,
  8,2,2,8,2,2,8,2,2,
  4,4,4,8,
  
  20,
};

int speed=90;  //higher value, slower notes
int noteDuration;
int thisNote = 0;

void setup() {

  Serial.begin(9600);

}

void loop() {
    noteDuration = speed*noteDurations[thisNote];
    tone(3, melody[thisNote],noteDuration*1.9);
    Serial.println(melody[thisNote]);

    delay(noteDuration);

    noTone(3);
    thisNote=thisNote+1;
    if (thisNote >= 52)
    {
      thisNote=0;
      }
  // no need to repeat the melody.
}
