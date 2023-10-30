#include "blindStepper.h"

blindOpenClose::blindOpenClose()
{
    // Creates an instance
    blindOpenClose::myStepper.setMaxSpeed(blindOpenClose::speed);
    blindOpenClose::myStepper.setAcceleration(blindOpenClose::speed*4);
    blindOpenClose::myStepper.setSpeed(blindOpenClose::speed);
    pinMode(blindOpenClose::limitSwitchPin, INPUT);
    pinMode(blindOpenClose::manualSwitchPin, INPUT);
    
    // attachInterrupt(blindOpenClose::manualSwitchPin, blindOpenClose::ISR, FALLING);
}

bool blindOpenClose::motorHome()
{   
    // blindOpenClose::myStepper.moveTo(200*30);
    //    Rotate clockwise until limit switch is pressed
    if (digitalRead(blindOpenClose::limitSwitchPin))
    {
        // Number of steps to close the blind from fully closed?
        
        const int maxHomeSteps = 3 * blindOpenClose::stepsPerRev;
        
        const int homeSpeed = (blindOpenClose::speed)/5;
        blindOpenClose::myStepper.setMaxSpeed(homeSpeed);
        blindOpenClose::myStepper.setSpeed(homeSpeed);  
        blindOpenClose::myStepper.moveTo(maxHomeSteps);

        while (digitalRead(blindOpenClose::limitSwitchPin))
        {
            blindOpenClose::myStepper.run();
            if (blindOpenClose::myStepper.distanceToGo() == 0)
            {
                // Motor failed to home
                blindOpenClose::myStepper.setMaxSpeed(blindOpenClose::speed);
                blindOpenClose::myStepper.setSpeed(blindOpenClose::speed);
                return false;
            }
        }
        blindOpenClose::isBlindOpen = true;
        blindOpenClose::myStepper.setMaxSpeed(blindOpenClose::speed);
        blindOpenClose::myStepper.setSpeed(blindOpenClose::speed);
        blindOpenClose::myStepper.setCurrentPosition(0);
        return true;
    }
    else
    {
        // Motor is home
        blindOpenClose::isBlindOpen = true;
        blindOpenClose::myStepper.setSpeed(blindOpenClose::speed);
        return true;
    }
    

}
// void IRAM_ATTR blindOpenClose::ISR() 
// {
//     // Statements;
//     // blindOpenClose tyu;
//     // tyu.openClose();
// }

void blindOpenClose::autoManualMode()
{
  // We are in manual mode, change to auto mode
  if (blindOpenClose::pressAndHold)
  {
    blindOpenClose::pressAndHold = false;
  }
  // We are in auto mode change to manual
  else
  {
    blindOpenClose::pressAndHold = true;
  }
}

bool blindOpenClose::openClose()
{
const int maxSteps = 3 * blindOpenClose::stepsPerRev;
  if (blindOpenClose::isBlindOpen)
  {
    // Blind should close...
    blindOpenClose::myStepper.moveTo(-maxSteps);
    while (blindOpenClose::myStepper.distanceToGo() != 0)
    { 
      if (digitalRead(blindOpenClose::limitSwitchPin))
      {
        blindOpenClose::myStepper.run();
      }
      else
      {
        blindOpenClose::myStepper.setCurrentPosition(0);
        break;
      }
      
    }
    blindOpenClose::isBlindOpen = false;
  }
  else
  {
    blindOpenClose::myStepper.moveTo(maxSteps);
    while (blindOpenClose::myStepper.distanceToGo() != 0)
    {
      if (digitalRead(blindOpenClose::limitSwitchPin))
      {
        blindOpenClose::myStepper.run();
      }
      else
      {
        blindOpenClose::myStepper.setCurrentPosition(0);
        break;
      }
    }
    blindOpenClose::isBlindOpen = true;
  }
  blindOpenClose::myStepper.setCurrentPosition(0);
  return true;
}

// // Change direction once the motor reaches target position
// 	if (myStepper.distanceToGo() == 0) 
// 	  myStepper.moveTo(-myStepper.currentPosition());

// 	// Move the motor one step
// 	myStepper.run();