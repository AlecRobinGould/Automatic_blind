#include <Arduino.h>
#include "handler.h"

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);
  auto a = handler();
  
}

void loop() {
  // Serial.println(timeData.tm_year);

  delay(100);

}


// void IRAM_ATTR ISR() 
// {   
//   Serial.println("Button pressed");
  // Statements;
  // delay(100);
  // if (digitalRead(b.manualSwitchPin))
  // {
  //   if (b.pressAndHold)
  //   {
  //     Serial.println("Opening or closing");
  //     b.openClose();
  //   }
  //   else
  //   {
  //     Serial.println("Automode engaged, cannot open.");
  //   }
    
  // }
  // else
  // {
  //   delay(500);
  //   if (digitalRead(b.manualSwitchPin))
  //   {
  //     Serial.println("Opening or closing (longer press)");
  //     b.openClose();
  //   }
  //   else
  //   {
  //     // Press and hold, change manual and auto mode
  //     Serial.println("Button press and hold");
  //     b.autoManualMode();
  //   }
  // }
    
// }



    // auto x = getTime();
    // x.handleWifi();
    // delay(1000);
    // auto timeData = x.passTime();
    
    // auto b = riseandset();
    // b.setDate(timeData.tm_mday, timeData.tm_mon, timeData.tm_year);

    // int timeforsunrise = b.getSunriseHour();
   

    // int timeforsunrisemin = b.getSunriseMinute();
    // Serial.print(timeforsunrise);Serial.print(":");Serial.println(timeforsunrisemin);