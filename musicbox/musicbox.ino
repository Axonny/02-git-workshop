#include "pitches.h"
#include "button.h"
#include "buzzer.h"

#define PIN_BUTTON_MEL_ONE 3
#define PIN_BUTTON_MEL_TWO 4
#define PIN_BUTTON_OFF 5
#define PIN_BUTTON_SPEED 4
#define PIN_BUZZER 6

Button buttonMelodyOne(PIN_BUTTON_MEL_ONE);
Button buttonMelodyTwo(PIN_BUTTON_MEL_TWO);
Button buttonOff(PIN_BUTTON_OFF);
Button buttonSpeed(PIN_BUTTON_SPEED);
Buzzer buzzer(PIN_BUZZER);

int notes[] = {NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations[] = {8, 1, 4, 1};
int melodyLength = 4;

int notes2[] = {NOTE_C4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE};
double durations2[] = {4, 1, 4, 1};
int melodyLength2 = 4;

unsigned long speeds[] = {25, 50, 100, 200, 400, 800};
int currentSpeed = 2;
int speedsLength = 6;

int notes3[] = {NOTE_G4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_F4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_D4, NOTE_SILENCE, NOTE_C4, NOTE_SILENCE,
NOTE_A4, NOTE_SILENCE, NOTE_C5, NOTE_SILENCE, NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_F4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_D4, NOTE_SILENCE, NOTE_C4, NOTE_SILENCE,
NOTE_A4, NOTE_SILENCE, NOTE_C5, NOTE_SILENCE, NOTE_A4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_G4, NOTE_SILENCE, NOTE_F4, NOTE_SILENCE, NOTE_E4, NOTE_SILENCE, NOTE_D4, NOTE_SILENCE, NOTE_C4, NOTE_SILENCE};
double durations3[] {1,8,1,4,1,4,1,8,1,4,1,4, 1,4,1,4,1,4,1,4,1,10,1,8,1,4,1,4,1,8,1,4,1,4, 1,4,1,4,1,4,1,4,1,10,1,8,1,4,1,4,1,8,1,4,1,4, 1,4,1,4,1,4,1,4,1,10};
int melodyLength3 = 66;

void setup()
{
    buzzer.setMelody(notes, durations, melodyLength);
}

void loop()
{
    buzzer.playSound();

    if (buttonOff.wasPressed())
    {
        buzzer.turnSoundOff();
    }

    if (buttonMelodyTwo.wasPressed()){
      buzzer.setMelody(notes3, durations3, melodyLength3);
        buzzer.turnSoundOn();
    }

    if (buttonMelodyOne.wasPressed())
    {
        buzzer.setMelody(notes3, durations3, melodyLength3);
        buzzer.turnSoundOn();
    }

    if (buttonSpeed.wasPressed())
    {
        currentSpeed = (currentSpeed + 1)%speedsLength;
        buzzer.setNoteDuration(speeds[currentSpeed]);
    }
}
