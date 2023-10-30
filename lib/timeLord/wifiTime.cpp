#include <WiFi.h>
#include "time.h"

#include "wifiTime.h"


auto getTime::passTime() -> tm
{
    struct tm timeinfo;
    
    if(!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
    }
    // Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    // tm timeinfo;
    return timeinfo;
}

void getTime::handleWifi()
{   
    if (WiFi.status() != WL_CONNECTED)
    {
        Serial.println("Wifi connecting");
        WiFi.begin(getTime::ssid, getTime::password);
        while (WiFi.status() != WL_CONNECTED) {
            delay(500);
        }
        Serial.println("Wifi connected");
    }
    else
    {
        Serial.println("Wifi failed");
    }

    configTime( getTime::gmtOffset_sec,  getTime::daylightOffset_sec,  getTime::ntpServer);

}