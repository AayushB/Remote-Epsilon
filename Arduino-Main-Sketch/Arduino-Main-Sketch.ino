#include "Car.h"
#include "KeyController.h"
#include "Motor.h"
#include <Servo.h>

const int UPBUTTON=5;
const int DOWNBUTTON=2;
const int LEFTBUTTON=3;
const int RIGHTBUTTON=4;
const int STATEPIN=A0;


const int MOTORENABLEPIN=13;
const int MOTORINPUT1=11;
const int MOTORINPUT2=6;
const int SERVOPIN=9;


Car* myCar;
KeyController myKeyController(UPBUTTON,DOWNBUTTON, LEFTBUTTON, RIGHTBUTTON, STATEPIN);
    //enablePin controls the L293D IC on/off state
    //inputPin1 controls the front direction in an On state
    //inputPin2 controls the back direction in an On state
    //if input1 and input2 have the same state then there is no flow of current through
    //the motor
    //the upPin controls the input of a push button programmed with the frontal direction
    //the downPin controls the input of a push button programmed with the backwards direction
    //the leftPin controls the input of a push button programmed with the left direction
    //the rightPin controls the input of a push button programmed with the right direction
    //the statepin controls the on/off and drive,neutral, and reverse moode

void setup()
{
  Serial.begin(9600);
  myCar= new Car(MOTORENABLEPIN, MOTORINPUT1, MOTORINPUT2, SERVOPIN);
}

void loop()
{
  myCar->update(myKeyController); //when user enters input the input is sent to the keycontroller class
  //which is then sent to the update function in the car class and updates the current state of the car
}
