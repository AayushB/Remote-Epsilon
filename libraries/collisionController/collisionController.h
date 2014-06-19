#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H
#include "Arduino.h"

class collisionController
{
public:
    collisionController(int echoPin,triggerPin);
    void echo();//detects distance from object in front
    void detectionResponse();

protected:
private:
    double duration, distance;
    int maxRange, minRange;
};

#endif // COLLISIONCONTROLLER_H
