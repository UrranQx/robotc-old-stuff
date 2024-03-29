#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Sensor, S3,     ,               sensorI2CCustom)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-compass.h"
int alpha=0,v=50;


task comp()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	float u,k=3;
	wait1Msec(200);
	int err;
	alpha= compass.heading;
	while(true)
	{
		err=alpha-compass.heading;
		u=k*(err-err/180*360);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}

}
task main()
{
	startTask(comp);
	for(int i=0;i<4;i++)
	{
		sleep(1000);
		alpha=(alpha+90)%360;
		sleep(245);
		alpha=(alpha-90+360)%360;
	}
	for(int n=0;n<2;n++)
	{
		alpha=(alpha+90)%360;
		sleep(245);

	}
	for(int gamma=0;gamma<1;gamma++)
	{

		sleep(245);
		alpha=-(alpha-90+360)%360;

	}
	for(int beta=0;beta<4;beta++)
	{
		sleep(1000);
		alpha=(alpha+90)%360;
		sleep(245);
		alpha=-(alpha-90+360)%360;

	}
}
