#include <WiFi.h>
#include "time.h"

#ifndef wifiTime_h
#define wifiTime_h

class getTime
{
    private:
        const char* ssid       = "yourssid";
        const char* password   = "yourpass";

        const char* ntpServer = "pool.ntp.org";
        const long  gmtOffset_sec = 0;
        const int   daylightOffset_sec = 3600;

    public:
        

        auto passTime() -> tm;
        void handleWifi();
};

#endif
// void printLocalTime()
// {
//   struct tm timeinfo;
    
//   if(!getLocalTime(&timeinfo)){
//     Serial.println("Failed to obtain time");
//     return;
//   }
//   Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
// }

// void setup()
// {
//   Serial.begin(115200);
  
//   //connect to WiFi
//   Serial.printf("Connecting to %s ", ssid);
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//       delay(500);
//       Serial.print(".");
//   }
//   Serial.println(" CONNECTED");
  
//   //init and get the time
//   configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
//   printLocalTime();

//   //disconnect WiFi as it's no longer needed
//   WiFi.disconnect(true);
//   WiFi.mode(WIFI_OFF);
// }

// void loop()
// {
//   delay(1000);
//   printLocalTime();
// }