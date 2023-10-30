#include "getSunriseSunset.h"
// what is our longitude (west values negative) and latitude (south values negative)



void riseandset::setDate(int day, int month, int year)
{
  // today[] = { 0, 0, 12, 30, 9, 23 }; // store today's date (at noon) in an array for TimeLord to use (format SS, MM, HH, DD, MM, YY)
  // Serial.println(day);
  // Serial.println(month+1);
  // Serial.println(year-100);
  // day = 30;
  // month = 9;
  // year = 23;
  today[0] = 0;
  today[1] = 0;
  today[2] = 12;
  today[3] = day;
  today[4] = (month+1);
  today[5] = (100-year);

  capetown.TimeZone(2 * 60); // tell TimeLord what timezone your RTC is synchronized to. You can ignore DST
  // as long as the RTC never changes back and forth between DST and non-DST
  capetown.Position(riseandset::LATITUDE, riseandset::LONGITUDE); // tell TimeLord where in the world we are

}

int riseandset::getSunriseHour()
{ 
  // return 18;
  if (capetown.SunRise(today)) // if the sun will rise today (it might not, in the [ant]arctic)
  {
    return (int) today[tl_hour];
  }

  else 
  {
    return 6;
  }
}

int riseandset::getSunriseMinute()
{
  // return 3;
  if (capetown.SunRise(today)) // if the sun will rise today (it might not, in the [ant]arctic)
  {
    return (int) today[tl_minute];
  }
  else
  {
    return 0;
  }

}

int riseandset::getSunsetHour()
{
  // return 17;
  if (capetown.SunSet(today)) // if the sun will set today (it might not, in the [ant]arctic)
  {
    // Serial.print((int) today[tl_hour]);Serial.print(":");
    return (int) today[tl_hour];
  }
  else
  {
    return 18;
  }


}
int riseandset::getSunsetMinute()
{
  // return 55;
  if (capetown.SunSet(today)) // if the sun will set today (it might not, in the [ant]arctic)
  {
    // Serial.println((int) today[tl_minute]);
    return (int) today[tl_minute];
  }
  else
  {
    return 0;
  }

}
