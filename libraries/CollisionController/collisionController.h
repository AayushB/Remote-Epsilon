/**
 *CollisionController
 *Copyright 2014
 *Written by Aayush Bhandari, Wilson Hoang
 *6/19/2014
 **/
#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H
#include "Arduino.h"
#include <NewPing.h>
#include <Servo.h>

class CollisionController
{
public:
    CollisionController(int echoPin,int triggerPin, int servoPin);
    //echoPin controls the input of the HC-SR04 which emitts the ping
    //triggerPin controls the input of the HC-SR04 which recieves the echo which is used to compute the distance
    double recieveDistance();
    //takes in the distance from sonar object which is converted to cm and then printed.
    
    int recieveAngle();
    //recieves the angle at which the HC-SR04 takes in the largest distance.
    
private:
    //This is part of HC-SR04
    double distance;
    NewPing* sonar;
    int echoPin;
    int triggerPin;
    //this is part of the servo moto
    int angle;
    Servo myServo;
    int servoPin;
    //this is part the time delay without using delay();
    int prevMillis;
    int interval;

    
};

#endif
