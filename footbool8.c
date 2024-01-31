#pragma config(Sensor, S1,     ,               sensorI2CHiTechnicCompass)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-irseeker-v2.h"
#include "hitechnic-compass.h"
task main ()
{
	float u, v=50,err, ks=0.2,e=0;
	wait1Msec(100);
	tHTMC compass;
	initSensor(&compass, S2);
	sleep(200);
	readSensor(&compass);
	compass.offset = compass.heading;
	int alpha=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker, S3);
	while(true)
	{
		//readSensor(&compass);
		readSensor(&irSeeker);
		if (irSeeker.acValues[2]>160)
		{
			readSensor(&compass);
			err=alpha-compass.heading;
			u=0.4*err;
		}
		else
		{

			e=alpha-compass.heading;
			e=e-(e/180)*360;
			int sector=5+ks*e/30.0;
			err=sector-irSeeker.acDirection;
			u=err*10;
		}

		int mB=v-u;
		int mC=v+u;
		if (abs(mB)>100) mB=sgn(mB)*100;
		if (abs(mC)>100) mC=sgn(mC)*100;
		motor[motorB]=mB;
		motor[motorC]=mC;
		sleep(10);
	}
}
