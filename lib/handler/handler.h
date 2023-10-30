#include "timeKeeper.h"
#include "blindStepper.h"

#ifndef handler_h
#define handler_h


class handler
{
    private:
        void handleThings();
        bool openCloseOnce;
    public:
        handler();
};


#endif

// auto c = keepTime();
// auto b = blindOpenClose();
// void setup() {

//   // put your setup code here, to run once:
//   Serial.begin(115200);
  
  
//   attachInterrupt(b.manualSwitchPin, ISR, FALLING);

//   Serial.println("Motor homing");
//   b.motorHome();

  

// }

// void loop() {
//   // Serial.println(timeData.tm_year);


//   // Run isittime to see if motor must turn
//   Serial.println(c.isitTime());
//   if (b.pressAndHold)
//   {
//     Serial.println("Manual mode");
//   }
//   else
//   {
//     if (c.isitTime())
//     {
//       Serial.println("Auto mode, and its time!");
//       b.openClose();
//     }
//   }

//   delay(100);

// }


// void IRAM_ATTR ISR() 
// {   
//   Serial.println("Button pressed");
//   // Statements;
//   delay(100);
//   if (digitalRead(b.manualSwitchPin))
//   {
//     if (b.pressAndHold)
//     {
//       Serial.println("Opening or closing");
//       b.openClose();
//     }
//     else
//     {
//       Serial.println("Automode engaged, cannot open.");
//     }
    
//   }
//   else
//   {
//     delay(500);
//     if (digitalRead(b.manualSwitchPin))
//     {
//       Serial.println("Opening or closing (longer press)");
//       b.openClose();
//     }
//     else
//     {
//       // Press and hold, change manual and auto mode
//       Serial.println("Button press and hold");
//       b.autoManualMode();
//     }
//   }
    
// }