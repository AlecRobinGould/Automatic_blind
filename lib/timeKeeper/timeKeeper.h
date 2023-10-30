#include "getSunriseSunset.h"
#include "wifiTime.h"

#ifndef timeKeeper_h
#define timeKeeper_h

class keepTime
{
    private:
        
        
        getTime requestTime;
        riseandset requestRiseSet;
        bool sunRiseorSunSet();

        int minuteNow;
        int hourNow;
        int yearNow;

        int sunRiseHour;
        int sunRiseMinute;
        int sunSetHour;
        int sunSetMinute;
    public:
        keepTime();
        bool isitTime();
        bool beforeSunRise = false;
        bool beforeSunSet = false;
};

#endif