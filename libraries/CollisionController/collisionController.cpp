/**
 *CollisionController
 *Copyright 2014
 *Written by Aayush Bhandari, Wilson Hoang
 *6/19/2014
 **/
#include "CollisionController.h"
CollisionController::CollisionController(int echoPin, int triggerPin,int servoPin)
{
    this->echoPin=echoPin;
    this->triggerPin=triggerPin;
    this->servoPin=servoPin;
    int MAX_DISTANCE=500;
    
    sonar= new NewPing(echoPin,triggerPin,MAX_DISTANCE);//creating NewPing object
    //sonar
    
    angle=90;
    myServo.attach(servoPin);
    myServo.write(angle);
    //delay without using delay();
    prevMillis=0;
    interval=60;
    
}
double CollisionController::recieveDistance()
{
    int uS=sonar->ping();// gets the distance and set it to uS to convert to cm later
    distance=uS/US_ROUNDTRIP_CM;//converting the uS to cm and setting it to distance
    return distance;
}


int CollisionController::recieveAngle()
{
    int myAngle;
    double maxDistance=0;
    
    myServo.write(0);
    
    for(int currentAngle=0; currentAngle < 200; )
    {
        unsigned long currMillis=millis();//sets the current time to the time since

        if(currMillis-prevMillis  > interval)// 60 ms delay
        {
            prevMillis=currMillis;// set the previous time to current time
            myServo.write(currentAngle);//assigning currentAngle to servo
            double distance= sonar->ping();//determining distance
            if(maxDistance < distance)
            {
                myAngle=currentAngle;//setting myAngle if the distance at said angle is has the largest distance
                maxDistance=distance;//setting the distance at angle
            }
            currentAngle+=10;
        }
    }
    myServo.write(angle);
    return myAngle;
}
