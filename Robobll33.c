
#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"
int alpha=0,beta=0;
task comp ()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	float u,v=40,ks=0.2,kir,kirmin=8,kr=0.5;
	int err;

	while (true)
	{


		readSensor(&irSeeker);



		motor[motorB]=v+u;
		motor[motorC]=v-u;
		sleep(1);
	}
}
task main ()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	float u,v=68,kr=0.5;
	int err;
	alpha=compass.heading;
	while(true)
	{ readSensor(&irSeeker);
		if 	(irSeeker.acValues[2]>60)
		{	readSensor(&compass);
			displayTextLine(2,"IR=%d",irSeeker.acDirection);
			displayTextLine(6,"err=%d",err);
			readSensor(&compass);
			err=alpha-compass.heading;
			u=(irSeeker.acDirection-5)*(err-err/180*360)*(-1);
			/*		startTask  (comp);
			readSensor(&compass);
			displayTextLine(2,"IR=%d",irSeeker.acDirection);
			displayTextLine(6,"err=%d",err);
			err=alpha-compass.heading;
			u=0.3*err*(-1);
			*/


		}
		else
		{
			err=irSeeker.acDirection-5;
			u=37*err;

		}
		/*	int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*100;
		if(abs(mC)>100) mB=sgn(mC)*100;
		*/
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		sleep(10);
	}
}
