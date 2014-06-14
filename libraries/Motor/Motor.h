/**
*Motor
*Copyright 2014
*Written by Aayush Bhandari & Wilson Hoang
*6/6/2014
**/
#ifndef Motor_Motor_h
#define Motor_Motor_h

#include <iostream>
#include "Arduino.h"

enum Direction{DRIVE, NEUTRAL, REVERSE};

class Motor
{
public:

    Motor(int enablePin, int inputPin1, int inputPin2);
    //enablePin controls the L293D IC on/off state
    //inputPin1 controls the front direction in an On state
    //inputPin2 controls the back direction in an On state
    //if input1 and input2 have the same state then there is no flow of current through
    //the motor
    void turnOn();
    //sets enablePin to HIGH which turns the L293D IC on
    void turnOff();
    //sets the enablePin to low which turns the L293D IC off
    //sets the inputPin1 to low
    //sets the inputPin2 to low
    //both input 1 and input 2 pins are set to low so there is no flow of current
    //through the motor
    void speedUp();
    //writes the speed to inputPin1 if direction = front
    //writes the speed to inputPin2 if directoin = back
    //increases speed until speed reaches 255
    void speedDown();
    //writes the speed to input1 if direction = front
    //writes the speed to inputPin2 if direction = back
    //decreases speed until speed reaches 0
    void stop();
    //sets inputPin1 and inputPin2 to LOW which means that there is no flow of current
    //through the motor
    void setDirection(Direction direction);
    //change direction of rotation to front or back

    //Accessors
    Direction getDirection();
    int getSpeed();

private:
    int enablePin;
    int inputPin1;
    int inputPin2;
    int speed;
    Direction direction;

};





#endif
