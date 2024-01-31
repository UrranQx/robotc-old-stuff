
#include "hitechnic-compass.h"
#include 	"hitechnic-irseeker-v2.h"
int alpha=0,beta=0,v=70;
int ek;
task preg()
{tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	alpha=compass.heading;
	while(true)
	{			readSensor(&compass);
		int e=alpha-compass.heading;
		ek=e-(e/180)*360;
		int	u=ek*1;
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);

	}
}
task main ()
{
	tHTMC compass;
	initSensor(&compass,S3);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker,S2);
	float u,v=70,ks=0.2,kir,kirmin=8;
	alpha=compass.heading;
	int err;
	int beta=alpha;

	while (true){
			int e=alpha-compass.heading;
		e=e-(e/180)*360;
		int sector=5+ks*e/30;
		int maxi=0;
		for (int i=0;i<1;i++)
			if(irSeeker.acValues[i]>maxi)
			maxi=irSeeker.acValues[i];
		kir=kirmin+100.0/(maxi+1);
		if (kir>30) kir=53;
		err=sector-irSeeker.acDirection;

		u=err*kir*(-1);

		readSensor(&irSeeker);


		int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*100;
		if(abs(mC)>100) mB=sgn(mC)*100;
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		sleep(10);

		displayTextLine(2,"IR=%d",irSeeker.acDirection);
		displayTextLine(6,"err=%d",err);
		alpha=beta;sleep(500);
		if(abs(ek)<30)
			if(SensorValue[S3]>60)
			{alpha=beta+30;sleep(1500);}
	else
	if(SensorValue[S3]<40)
	{alpha= beta-30;sleep(1500);}
}	startTask(preg);


}
