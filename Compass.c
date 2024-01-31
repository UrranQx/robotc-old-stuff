#include "hitechnic-compass.h"
task main()
{
tHTMC compass;
initSensor(&compass,S2);
sleep(200);
readSensor(&compass);
compass.offset=compass.heading;
displayBigTextLine(4, "Target: %4d", compass.offset);
while(true)
{
	readSensor(&compass);
	displayBigTextLine(6, "Abs: %4d", compass.heading);
	displayBigTextLine(8, "Rel: %4d", compass.relativeHeading);
	sleep(10);
}


}
