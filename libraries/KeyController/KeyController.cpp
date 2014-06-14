/**
*KeyController
*Copyright 2014
*Written by Aayush Bhandari, Wilson Hoang, Russell Leong
*6/11/2014
**/
//----------------------------------------------------------------------------------------------------------------------------------------------------
//KeyController Class
//----------------------------------------------------------------------------------------------------------------------------------------------------

#include "KeyController.h"
KeyController::KeyController(int upPin, int downPin,int leftPin, int rightPin, int statePin)
{
    //assigning the buttons

    this->upPin=upPin;
    this->downPin=downPin;
    this->leftPin=leftPin;
    this->rightPin=rightPin;
    this->statePin=statePin;

    pinMode(this->upPin, INPUT);
    pinMode(this->downPin, INPUT);
    pinMode(this->leftPin, INPUT);
    pinMode(this->rightPin, INPUT);
    pinMode(this->statePin, INPUT);
}


bool KeyController::upPinActive(){//activates the up button when pressed
    if(digitalRead(upPin)){
        return true;
    }else{
        return false;
    }
}

bool KeyController::downPinActive(){//returns true if the down button is pressed
    if(digitalRead(downPin)){
        return true;
    }else{
        return false;
    }
}

bool KeyController::leftPinActive(){//returns true if the left button is pressed
    if(digitalRead(leftPin)){
        return true;
    }else{
        return false;
    }
}

bool KeyController::rightPinActive(){//returns true if the the right button if pressed
    if(digitalRead(rightPin)){
        return true;
    }else{
        return false;
    }
}

bool KeyController::onPinActive(){//returns true if the on button is true , 1023 (no resistance) is the resistance for on switch
    if(analogRead(statePin)==1023){
        return true;
    }else{
        return false;
    }
}

bool KeyController::drivePinActive(){//returns true if the gear is set to drive mode, resistance between 990 and 1010
    if(analogRead(statePin)>=990 && analogRead(statePin) <=1010){
        return true;
    }else{
        return false;
    }
}

bool KeyController::neutralPinActive(){//returns true if the gear is set to  neutral mode, resitance between 505 and 515
    if(analogRead(statePin)>=505 && analogRead(statePin)<=515){
        return true;
    }else{
        return false;
    }
}

bool KeyController::reversePinActive(){//returns true if the gear is set to  reverse mode
    if(analogRead(statePin)>=5 && analogRead(statePin)<=10){
        return true;
    }else{
        return false;
    }

}
