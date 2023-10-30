#include <Arduino.h>
#include "TimeLord.h"


class riseandset{
    TimeLord capetown;
    
    byte today[6];

    float const LONGITUDE = 18.870831871173444;
    float const LATITUDE = -33.79536054197728;

    public:
        int getSunriseHour();
        int getSunriseMinute();
        int getSunsetHour();
        int getSunsetMinute();
        void setDate(int day, int month, int year);
};