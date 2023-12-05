# Automatic_blind

Firmware for an automated blind control system. The system makes use of a stepper motor to rotate a blind open and closed. An ESP 32 makes use of NTP to obtain time to determine if its sunrise or sunset.

The GPS co-ordinated are used in conjunction with the date to calculte the sunrise and sunset time - accurate to the minute (https://gml.noaa.gov/grad/solcalc/calcdetails.html).

Firmware developed for this project can be found in /lib. The Main.cpp is located in /src.

![image](https://github.com/AlecRobinGould/Automatic_blind/assets/95220293/170f74e8-3c58-4995-a674-4e5d475c5690)

![SMvsdx](https://github.com/AlecRobinGould/Automatic_blind/assets/95220293/0e681252-c048-4ec0-98fc-be9b4478a0fd)
