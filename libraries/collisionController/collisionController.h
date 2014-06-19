#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H
#include "Arduino.h"
#include <NewPing.h>

class collisionController
{
public:
    collisionController(int echoPin,triggerPin);
    double recieveDistance();
    
protected:
private:
    double distance;
    NewPing* sonar;
};

#endif