
#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"
int alpha=0,beta=0;
task main ()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S3);
	float u,v=15,ks=0.2,kir,kirmin=8,kr=0.5;
	int err;
	alpha=compass.heading;
	while (true)
	{
		readSensor(&compass);
		displayTextLine(2,"IR=%d",irSeeker.acDirection);
		displayTextLine(6,"err=%d",err);
		int e=irSeeker.acDirection-5;
		int beta = alpha+kr*e*30;
		err=beta-compass.heading;

		err=err-(err/180)*360;


		u=err*1.1;

		readSensor(&irSeeker);


		int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*100;
		if(abs(mC)>100) mB=sgn(mC)*100;
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		sleep(10);
	}
}
