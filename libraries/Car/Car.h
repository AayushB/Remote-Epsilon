/**
*Motor
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
#include "CollisionController.h"
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
    //main update for the car, includes basic movement and steering
    void update(KeyController controller);
    //collision sesnor update for the car
    void collisionUpdate(CollisionController controller);
    
    
private:
    Motor* myMotor;
    //this is part of the delay
    long prevMillisUp;
    long prevMillisDown;
    long prevMillisOn;
    long prevMillisMode;
    long intervalUp;
    long intervalDown;
    long intervalOn;
    long intervalMode;
    //this is part of Servo
    Servo myServo;
    int angle;
    int servoPin;
    //this is the state of the car whther its on or off
    bool on;
};

#endif

