#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"
task main()

{int v=50,u;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	displayBigTextLine(4, "Target: %4d", compass.offset);
	int alpha=SensorValue[S2];
	while(true)
	{	readSensor(&irSeeker);
		if(SensorValue[S3]>200)
			{
		 u=3*(SensorValue[S2]-(SensorValue[S2]-alpha)/180*360-alpha);
		}
		else
		{

	}
	motor[motorB]=v+u;
	motor[motorC]=v-u;
	}


}
