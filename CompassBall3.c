#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Sensor, S3,     ,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"

task main ()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	//	readSensor(&compass);
	compass.offset=compass.heading;
	int alpha=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	float u,v=20,err;
	while(true)
	{
		readSensor(&irSeeker);
		if (irSeeker.acValues[2]>100)
		{readSensor(&compass);
			err=alpha-compass.heading;

			u=-0.4*err;
		}
		else {
			err = irSeeker.acDirection-5;
			u=err*(-5);
		}
		int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*100;
		if(abs(mC)>100) mB=sgn(mC)*100;
		motor[motorB]=mB;
		motor[motorC]=mC;
		sleep(10);
	}
}
