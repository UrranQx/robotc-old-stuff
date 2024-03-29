#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-irseeker-v2.h"
#include "hitechnic-compass.h"
#include "hitechnic-sensormux.h"
task main ()
{
	float u, v=55, err, ks=0.25,e=0,kr=0.25;
	float kir, kirmin=8;
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
			u=-1.5*err;
		}
		else
		{

			e=alpha-compass.heading;
			e=e-(e/180)*360;
			int sector=5+ks*e/30.0;
			int maxi=0;
			for(int i=0; i<5; i++)
				if(irSeeker.acValues[i]>maxi)
				maxi=irSeeker.acValues[i];
			kir=kirmin+50.0/(maxi+1);
			if (kir>30) kir=30;
			err=sector-irSeeker.acDirection;
			int beta = alpha + kr*e*30;
			err=beta-compass.heading;
			err=err-(err/180)*360;
			u=err*0.5;

			u=-err*kir;
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
