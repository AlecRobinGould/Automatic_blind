#include <AccelStepper.h>

#ifndef blindStepper_h
#define blindStepper_h

// Define motor interface type
#define motorInterfaceType 1

class blindOpenClose
{
    private:
        // set the maximum speed, acceleration factor,
        // initial speed and the target position
        // Define pin connections
        const int dirPin = 5;
        const int stepPin = 18;
        int speed = 500;

        const int stepsPerRev = 200;

        AccelStepper myStepper = AccelStepper(motorInterfaceType, blindOpenClose::stepPin, blindOpenClose::dirPin);

        const int limitSwitchPin = 2;

    public:
        const int manualSwitchPin = 15;
        bool isBlindOpen;
        bool pressAndHold = false;
        blindOpenClose();
        bool motorHome();
        void autoManualMode();
        bool openClose();
};


#endif