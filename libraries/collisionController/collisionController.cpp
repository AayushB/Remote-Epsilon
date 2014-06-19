#include "collisionController.h"

collisionController::collisionController(int echoPin, int triggerPin)
{
    this->echoPin=echoPin;
    this->triggerPin=triggerPin;
    int MAX_DISTANCE=500;
    
    sonar= new NewPing(echoPin,triggerPin,MAX_DISTANCE);
}
double recieveDistance(){
    int uS=sonar->ping();
    distance=uS/US_ROUNDTRIP_CM;
    Serial.print(distance);
    Serial.println("cm");
    return distance;
}