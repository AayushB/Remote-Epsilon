/**
*Car
*Copyright 2014
*Written by Aayush Bhandari, Wilson Hoang, Russell Leong, Jason Huang
*6/11/2014
**/
//--------------------------------------------------------------------------------------
//                                  Car Class
//--------------------------------------------------------------------------------------

#ifndef Car_Car_h
#define Car_Car_h
#include "Motor.h"
#include <Servo.h>
#include "KeyController.h"
class Car
{
public:
    //this class needs to instantiated inside the setup function or else the servo will not get attached
    Car(int enablePin, int motorInputPin1, int motorInputPin2, int servoPin);
    //enablePin controls the L293D IC on/off state
    //motorInputPin1 controls the front direction in an On state
    //motorInputPin2 controls the back direction in an On state
    //servoPin contols the servo motor
    void setMode(Direction direction);
    void update(KeyController controller);
    
private:
    Motor* myMotor;
    Servo myServo;
    long prevMillisUp;
    long prevMillisDown;
    long prevMillisOn;
    long prevMillisMode;
    long intervalUp;
    long intervalDown;
    long intervalOn;
    long intervalMode;
    int angle;
    int servoPin;
    bool on;
};

#endif

