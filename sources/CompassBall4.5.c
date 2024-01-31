#pragma config(Sensor, S3, HTIRS2,sensorI2CCustom)
#pragma config(Sensor, S2,, sensorI2CHiTechnicCompass)

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
	float u,v=26,err,ks=0.2,e=0,kir,kirmin=8;
	while(true)
	{
		readSensor(&irSeeker);
		if (irSeeker.acValues[2]>160)
		{
			readSensor(&compass);
			err=alpha-compass.heading;
			u=-0.4*err;
		}
		else
		{
			e=alpha-compass.heading;
			e=e-(e/180)*360;
			int sector=5+ks*e/30.0;
			int maxi=0;
			for(int i=0;i<5;i++)
				if(irSeeker.acValues[i]>maxi)
				maxi=irSeeker.acValues[i];
			kir=kirmin+50.0/(maxi+1);
			if(kir>30) kir=30;
			err=sector-irSeeker.acDirection;
			//	err = irSeeker.acDirection-5;
			u=err*(-kir);
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
