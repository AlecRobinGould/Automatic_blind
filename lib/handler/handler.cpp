#include "handler.h"
#include "Adafruit_SH1106.h"

#define OLED_SDA 21
#define OLED_SCL 22

handler::handler()
{
    handler::handleThings();
    handler::openCloseOnce = false;
}

void handler::handleThings()
{
    auto handleOpenClose = blindOpenClose();
    auto handleTimings = keepTime();
    Adafruit_SH1106 display(21, 22);
    display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Auto blind");
    display.display();
    delay(2000);
    display.clearDisplay();

    // if(WiFi.status() != WL_CONNECTED)
    // {
    //     Serial.println("WiFi connected");
    //     display.println("WiFi Connected");
    //     display.display();
    // }
    
    // while (WiFi.status() != WL_CONNECTED)
    // {
    //     delay(100);
    // }
    bool dispMode = false;
    if (handleOpenClose.motorHome())
    {
        // Motor homed successfully
    }
    while (true)
    {
        
        
        // Button not pressed
        if (digitalRead(handleOpenClose.manualSwitchPin))
        {
            // if (handleOpenClose.pressAndHold)
            // {
            // Serial.println("Opening or closing");
            // handleOpenClose.openClose();
            // }
            // else
            // {
            // Serial.println("Automode engaged, cannot open.");
            // }
            if (handleOpenClose.pressAndHold)
            {
                // Serial.println("Manual mode, do nothing");
                if (!dispMode)
                {
                    display.clearDisplay();
                    display.setCursor(0,0);
                    display.println("Manual");
                    display.println("Mode");
                    display.display();
                    dispMode = true;
                }
                
            }
            else
            {   
                // Serial.println("Auto mode, do nothing");
                if (!dispMode)
                {
                    display.clearDisplay();
                    display.setCursor(0,0);
                    display.println("Auto Mode");
                    display.display();
                    dispMode = true;
                }
                if (handleTimings.isitTime())
                {
                    // Serial.println("Auto mode, and its time!");
                    if(!handler::openCloseOnce)
                    {
                        // bool beforeSunRise = false;
                        // bool beforeSunSet = false;
                        Serial.println(handleTimings.beforeSunRise);
                        Serial.println(handleTimings.beforeSunSet);
                        Serial.println(handleOpenClose.isBlindOpen);
                        if(handleTimings.beforeSunRise && !handleOpenClose.isBlindOpen)
                        {
                            handleOpenClose.openClose();
                            handler::openCloseOnce = true;
                        }
                        else if(handleTimings.beforeSunSet && handleOpenClose.isBlindOpen)
                        {
                            handleOpenClose.openClose();
                            handler::openCloseOnce = true;
                        }
                        
                    }
                
                }
                else
                {
                    handler::openCloseOnce = false;
                }
            }
            
        }
        else
        {

            // Serial.println("Button pressed");
            delay(500);
            if (digitalRead(handleOpenClose.manualSwitchPin))
            {   
                if (handleOpenClose.pressAndHold)
                {
                    // Serial.println("Opening or closing (longer press)");
                    handleOpenClose.openClose();
                }
                else
                {
                    // Serial.println("Button pressed in automode");
                }
                
            }
            else
            {
            // Press and hold, change manual and auto mode
            // Serial.println("Button press and hold");
            handleOpenClose.autoManualMode();
            dispMode = false;
            while (!digitalRead(handleOpenClose.manualSwitchPin))
            {
                delay(200);
            }
            }
        }
    }
    
        
}
