
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
	float u,v=40,ks=0.2,kr=0.5,kirmin=8;
	int err;
	alpha=compass.heading;
	while(true)
	{ readSensor(&irSeeker);
		if 	(irSeeker.acValues[2]>173)
		{
			readSensor(&compass);

			err=alpha-compass.heading;//-SensorValue[S1];
			u=0.4*err*(-1);
		}

		else
		{





			int e=alpha-compass.heading;
			e=e-(e/180)*360;
			int sector=5+ks*e/30;
			int maxi=0;
			for (int i=0;i<5;i++)
				if(irSeeker.acValues[i]>maxi)
				maxi=irSeeker.acValues[i];
			int	kir=kirmin+50.0/(maxi+1);
			if (kir>30) kir=30;
			err=sector-irSeeker.acDirection;

			u=err*kir*(-1);




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
