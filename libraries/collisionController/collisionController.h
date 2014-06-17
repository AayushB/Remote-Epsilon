#ifndef COLLISIONCONTROLLER_H
#define COLLISIONCONTROLLER_H
#include "Arduino.h"

class collisionController
{
public:
    collisionController(int upPin, int downPin,int leftPin, int rightPin, int onPin, int drivePin, int neutralPin, int reversePin);
    bool onPinActive();
    bool drivePinActive();
    bool neutralPinActive();
    bool reversePinActive();
    bool frontDetect();//detects distance from object in front
    void detectionResponse();

protected:
private:
};

#endif // COLLISIONCONTROLLER_H
