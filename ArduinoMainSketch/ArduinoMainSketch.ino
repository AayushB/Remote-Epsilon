/**
*Motor
*Copyright 2014
*Written by Aayush Bhandari, Wilson Hoang
*6/11/2014
**/
//--------------------------------------------------------------------------------------
//                                  Car Class
//--------------------------------------------------------------------------------------

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
    //the UPBUTTON controls the input of a push button programmed with the frontal direction
    //the DOWNBUTTON controls the input of a push button programmed with the backwards direction
    //the LEFTUTTON controls the input of a push button programmed with the left direction
    //the RIGHTBUTTON controls the input of a push button programmed with the right direction
    //the STATEOPIN controls the on/off and drive,neutral, and reverse moode

void setup()
{
  Serial.begin(9600);
  myCar= new Car(MOTORENABLEPIN, MOTORINPUT1, MOTORINPUT2, SERVOPIN);
    //MOTORENABLEPIN controls the L293D IC on/off state
    //MOTORINPUT1 controls the front direction in an On state
    //MOTORINPUT2 controls the back direction in an On state
    //SERVOPIN attchaes a servo into that pin
}

void loop()
{
  myCar->update(myKeyController); //when user enters input the input is sent to the keycontroller class
  //which is then sent to the update function in the car class and updates the current state of the car
}
