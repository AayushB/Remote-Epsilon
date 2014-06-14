/**
*Car
*Copyright 2014
*Written by Aayush Bhandari, Wilson Hoang, Russell Leong, Jason Huang
*6/11/2014
**/
//--------------------------------------------------------------------------------------
//                                  Car Class
//--------------------------------------------------------------------------------------

#include "Car.h"


Car::Car(int enablePin, int inputPin1, int inputPin2, int servoPin)
{

    myMotor = new Motor(enablePin, inputPin1, inputPin2);	//Create a new motor object
    myMotor->turnOn();
    myMotor->setDirection(NEUTRAL);
    this->servoPin=servoPin;
    myServo.attach(this->servoPin);
    prevMillisUp=0;//previous time for up
    prevMillisDown=0;//previous time for down
    prevMillisOn=0;
    prevMillisMode=0;
    intervalUp=40;
    intervalDown=10;
    intervalOn=200;
    intervalMode=200;
    angle=90;//setting servo motors base angle
    myServo.write(angle);
    
    on=false;

}

void Car::setMode(Direction direction)
{											//Set Direction
	myMotor->setDirection(direction);
}

void Car::update(KeyController controller)
{
    unsigned long currMillis=millis();//sets the current time to the time since

    if(controller.onPinActive() && (currMillis-prevMillisOn)  > intervalOn)
    {
            prevMillisOn=currMillis;// set the previous time to current time
            on=!on; // turns on and off the car
            if(!on)
            {
                myMotor->turnOff();
            }
            Serial.println(on);
    }
    
    if(on)
    {
        //--------------------------------------------------------------------
        //                                  SERVO        the servo library disables PWM use on pins 9 and 10
        //--------------------------------------------------------------------

        if(controller.leftPinActive())//if users presses the left button
        {
        // Serial.println("left is being pressed");
            if(angle > 0)//angle cant be less than 0
            {
                //Serial.println(angle);

                angle=0;;//chnages angle to 0
            }
        }

        if(controller.rightPinActive())//if user presses the right button
        {

        // Serial.println("right is being pressed");
            if (angle < 179)//angle cant be greater than 179
            {
                angle=179;;//changes angle to 179
            }
        }

        if(!(controller.leftPinActive()||controller.rightPinActive() ))//if nothing is pressed
        {

            if (angle >= 0 && angle < 90)
            {
                angle=90;//set angle to 90 by default if current angle is less than 90
            }

            if ( angle >90 && angle <= 185)
            {
                angle=90;// set angle to 90 by default if current angle is greater than 90
            }
        }
        myServo.write(angle);

        //--------------------------------------------------------------------
        //                      Motor
        //--------------------------------------------------------------------

        //unsigned long currMillis=millis();//sets the current time to the time since
        
        if(controller.reversePinActive() && (currMillis-prevMillisMode)  > intervalMode)
        {
            prevMillisMode=currMillis;// set the previous time to current time){
            myMotor->setDirection(REVERSE);
        }
        if(controller.drivePinActive() && (currMillis-prevMillisMode)  > intervalMode)
        {
            prevMillisMode=currMillis;// set the previous time to current time){
            myMotor->setDirection(DRIVE);
        }
            
        if(controller.neutralPinActive() && (currMillis-prevMillisMode)  > intervalMode)
        {
            prevMillisMode=currMillis;// set the previous time to current time){
            myMotor->setDirection(NEUTRAL);
        }
        
        Serial.print("Mode:");
        Serial.println(myMotor->getDirection());
        
        unsigned long currMillis=millis();//sets the current time to the time since
        //the arduino turned on
        //millis() is a timer that activates when arduino is turned on


        if(currMillis-prevMillisUp  > intervalUp) // This is the acceleration delay
        {
            prevMillisUp=currMillis;// set the previous time to current time
            if(controller.upPinActive() && myMotor->getDirection()!=NEUTRAL )
            {
            myMotor->speedUp();//speeds up the motor RPM while up button is being pressed
            }
            else
            {
                myMotor->speedDown();//slows down the motor RPM while up button is not pressed
            }
        }

        if((currMillis-prevMillisDown)  > intervalDown) // This is deccelration delay
        {
            prevMillisDown=currMillis;//sets the previous time to current time
            if(controller.downPinActive() && myMotor->getDirection()!=NEUTRAL)
            {
                myMotor->speedDown();//slows down motor RPM while down button is pressed
            }
        }
    }
}
