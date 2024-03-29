#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Sensor, S3,     ,               sensorI2CCustom)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

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
	float u,v=38,kr=0.5;
	int err;
	alpha=compass.heading;
	while(true)
	{ readSensor(&irSeeker);
		if 	(irSeeker.acValues[2]>170)
		{	readSensor(&compass);

			displayTextLine(2,"IR=%d",irSeeker.acDirection);
			displayTextLine(6,"err=%d",err);
			int e=irSeeker.acDirection-5;
			int beta = alpha+kr*e*30;
			err=beta-compass.heading;

			err=err-(err/180)*360;


			u=err*1.1*(-1);
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
			u=10*err;

		}

		/*		int mB=v+u;
		int mC=v-u;
		if(abs(mB)>100) mB=sgn(mB)*20;
		if(abs(mC)>100) mB=sgn(mC)*20;
		motor[motorB]=mB;
		motor[motorC]=mC;
		*/
		motor[motorB]=v+u;

		motor[motorC]=v-u;
		sleep(1);
	}
}
