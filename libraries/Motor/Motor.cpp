/**
*Motor
*Copyright 2014
*Written by Aayush Bhandari & Wilson Hoang
*6/6/2014
**/
#include "Motor.h"
Motor::Motor(int enablePin, int inputPin1, int inputPin2){
   //assigning buttons
    this->enablePin=enablePin;
    this->inputPin1=inputPin1;
    this->inputPin2=inputPin2;
    pinMode(enablePin,OUTPUT);
    pinMode(inputPin1,OUTPUT);
    pinMode(inputPin2,OUTPUT);
    digitalWrite(enablePin,LOW);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,LOW);
    direction=NEUTRAL;
}
void Motor::turnOn(){//setting the enable pin to high which turns on the motor
    digitalWrite(enablePin,HIGH);

}
void Motor::turnOff(){//setting the enable pin and the
    //input pints to low which turns off the motor
    digitalWrite(enablePin,LOW);
    digitalWrite(inputPin1,LOW);
    digitalWrite(inputPin2,LOW);

}
void Motor::speedUp()
{

    if(direction!=NEUTRAL)//if the  gear is not set to neutral
    {
        speed++;
        if(speed >=255)//speed cant exceed 255
        {
            speed=255;
        }

        if (direction==DRIVE)//if gear is set to drive
        {
            analogWrite(inputPin1,speed);//setting the speed for the front rotation
            digitalWrite(inputPin2,LOW);//safety measure to make sure only one inputPin is on
        }
        else if (direction == REVERSE)//if gear is set to reverse
        {
            analogWrite(inputPin2,speed);//setting the speed for the back rotation
            digitalWrite(inputPin1,LOW);//safety measure to make sure only one inputPin is on
        }
    }
}
void Motor::speedDown()
{
    if(direction!=NEUTRAL)//if gear is not set to neutral
    {
        speed--;
        if(speed<=0){//speed can not be less that 0
            speed=0;
        }
        if (direction==DRIVE)//if gear is set to drive
        {
            analogWrite(inputPin1,speed);//setting the speed for front rotation
            digitalWrite(inputPin2,LOW);//safety meausre to make sure only one inputPin is on
        }
        else if (direction== REVERSE)//if gear is set to reverse
        {
            analogWrite(inputPin2,speed);//setting the speed for back rotation
            digitalWrite(inputPin1,LOW);//safety meausre to make sure only one inputPin is on
        }
    }

}
void Motor::stop(){//sets the input pins to low so it no longer takes in input
    digitalWrite(inputPin1,LOW);//effectivly stopping
    digitalWrite(inputPin2,LOW);
    speed=0;

}
void Motor::setDirection(Direction direction)//sets the direction in which the wheel
{
    
    if(direction==NEUTRAL)
    {
        stop();//stops motor before setting to a mode
        this->direction=direction;// sets direction to neutral
    }
    else if(direction==REVERSE)
    {
        if(this->direction==NEUTRAL)
        {
            this->direction=direction;//if it is set on Neutral then set it to Reverse
        }
    }
    else if(direction==DRIVE)
    {
        if(this->direction==NEUTRAL)
        {
            this->direction=direction;//if it is set on Neutral then set it to Drive
        }
    }
}

Direction Motor::getDirection()
{
    return direction;
}

int Motor::getSpeed()
{
    return speed;
}
