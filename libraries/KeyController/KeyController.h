/**
*KeyController
*Copyright 2014
*Written by Aayush Bhandari, Wilson Hoang, Russell Leong
*6/11/2014
**/
#ifndef Car_KeyController_h
#define Car_KeyController_h
#include "Arduino.h"
//main class for KeyController
class KeyController
{
public:
    KeyController(int upPin, int downPin,int leftPin, int rightPin, int statePin);
    //the upPin controls the input of a push button programmed with the frontal direction
    //the downPin controls the input of a push button programmed with the backwards direction
    //the leftPin controls the input of a push button programmed with the left direction
    //the rightPin controls the input of a push button programmed with the right direction
    //the onPin controls the input of a push button programmed with the power to the entire
    //key controller
    //the drivePin controls the input of a push button programmed with the gear mode Drive
    //this sets wheel rotation to a clockwise
    //the neutralPin controls the input of a push button programmed with the gear mode Neutral
    //ignores input commands sent by keycontroller
    //the reversePin controls the input of a push button programmed with the gear mode Reverse
    //sets wheel rotation to counter clockwise
    bool upPinActive();//returns true if up Pin is Active, the upPin controls the input of a push button programmed with the frontal direction
    bool downPinActive();//returns true if down Pin is Active, the downPin controls the input of a push button programmed with the backwards direction
    bool leftPinActive();//returns true if left Pin is Active, the leftPin controls the input of a push button programmed with the left direction
    bool rightPinActive();//returns true if right Pin is Active, the rightPin controls the input of a push button programmed with the right direction
    bool onPinActive();//returns true if on Pin is Active, the onPin controls the input of a push button programmed with the power to the entire
    //key controller
    bool drivePinActive();//returns true if drive Pin is Active, the drivePin controls the input of a push button programmed with the gear mode Drive
     //this sets wheel rotation to a clockwise
    bool neutralPinActive();//returns true if neutral Pin is Active, the neutralPin controls the input of a push button programmed with the gear mode Neutral
    //ignores input commands sent by keycontroller
    bool reversePinActive();//returns true if reverse Pin is Active, the reversePin controls the input of a push button programmed with the gear mode Reverse
    //sets wheel rotation to counter clockwise

private:
    int upPin;
    int downPin;
    int leftPin;
    int rightPin;
    int statePin;

};
#endif
