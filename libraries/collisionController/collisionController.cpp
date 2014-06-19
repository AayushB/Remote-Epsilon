#include "collisionController.h"

collisionController::collisionController(int echoPin, int triggerPin)
{
    this->echoPin=echoPin;
    this->triggerPin=triggerPin;
    pinMode(this->triggerPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
    //maxRange=500;
    minRange=100;
}
void collisionController::echo()
{

    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin),LOW);
    duration=pulseIn(echoPin,HIGH);
    distance=duration/58.2;

}

void collisionController::detectionResponse()
{
    if(distance>=minRange)
    {
        //continue driving
    }
    else
    {
        //set mode to neutral or stop moving
    }
}
