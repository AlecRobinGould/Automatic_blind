#include "timeKeeper.h"


keepTime::keepTime()
{
    keepTime::requestTime.handleWifi();
}

bool keepTime::sunRiseorSunSet()
{
    auto dataTime = keepTime::requestTime.passTime();

    keepTime::hourNow = (dataTime.tm_hour + 1);
    keepTime::minuteNow = (dataTime.tm_min + 1);

    // keepTime::hourNow = 7;
    // keepTime::minuteNow = 26;

    keepTime::requestRiseSet.setDate(dataTime.tm_mday, dataTime.tm_mon, dataTime.tm_year);

    keepTime::sunRiseHour = keepTime::requestRiseSet.getSunriseHour();
    keepTime::sunRiseMinute = keepTime::requestRiseSet.getSunriseMinute();
    keepTime::sunSetHour = keepTime::requestRiseSet.getSunsetHour();
    keepTime::sunSetMinute = keepTime::requestRiseSet.getSunsetMinute();

    // Serial.print("Sunset: ");Serial.print(keepTime::sunSetHour);Serial.print(":");Serial.println(keepTime::sunSetMinute);
    // Serial.print("Sunrise: ");Serial.print(keepTime::sunRiseHour);Serial.print(":");Serial.println(keepTime::sunRiseMinute);
    // Check if its before sunrise
    if (keepTime::hourNow < keepTime::sunRiseHour)
    {
        keepTime::beforeSunRise = true;
        keepTime::beforeSunSet = false;
        return true;
    }
    else if ((keepTime::minuteNow <= keepTime::sunRiseMinute) && (keepTime::hourNow == keepTime::sunRiseHour))
    {
        keepTime::beforeSunRise = true;
        keepTime::beforeSunSet = false;
        return true;
    }
    // Check if its before sunset
    else if (keepTime::hourNow < keepTime::sunSetHour)
    {
        keepTime::beforeSunRise = false;
        keepTime::beforeSunSet = true;
        return true;
    }
    else if ((keepTime::minuteNow <= keepTime::sunSetMinute) && ((keepTime::hourNow == keepTime::sunSetHour)))
    {
        keepTime::beforeSunRise = false;
        keepTime::beforeSunSet = true;
        return true;
    }
    else
    {
        keepTime::beforeSunRise = false;
        keepTime::beforeSunSet = false;
        return false;
    }
    
}

bool keepTime::isitTime()
{
    if (keepTime::sunRiseorSunSet())
    {
        // Before sunrise
        if (keepTime::beforeSunRise && !keepTime::beforeSunSet)
        {
            if (keepTime::hourNow == keepTime::sunRiseHour)
            {
                if (keepTime::minuteNow == keepTime::sunRiseMinute)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
            
        }
        // After sunrise, before sunset
        else if (!keepTime::beforeSunRise && keepTime::beforeSunSet)
        {
            if (keepTime::hourNow == keepTime::sunSetHour)
            {
                if (keepTime::minuteNow == keepTime::sunSetMinute)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    // After sunrise and sunset, dont waste time checking
    else
    {
        return false;
    }
}