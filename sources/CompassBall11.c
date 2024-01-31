
#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"
int alpha=0;
task main ()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	float u,v=40;
	int err;
	alpha=compass.heading;
	while(true)
	{ readSensor(&irSeeker);
		if 	(irSeeker.acValues[2]>140)
		{
			readSensor(&compass);
			displayTextLine(2,"IR=%d",irSeeker.acDirection);
			displayTextLine(6,"err=%d",err);
			err=alpha-compass.heading;
			u=0.3*err*(1);
		}
		else
		{
			err=irSeeker.acDirection-5;
			u=12*err;

		}
		int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*100;
		if(abs(mC)>100) mB=sgn(mC)*100;

		motor[motorB]=v+u;
		motor[motorC]=v-u;
		sleep(10);
	}
}
