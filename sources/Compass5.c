#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_GenericI2C)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-compass.h"
task main()
{
	tHTMC compass;
	initSensor(&compass,S2);
	sleep(200);
	readSensor(&compass);
	compass.offset=compass.heading;
	displayBigTextLine(4, "Target: %4d", compass.offset);
	float u,k=3;
	int  v=40;


	int	black1 = SensorValue[S1];
	while(!getButtonPress(buttonUp))sleep(1);
	int	white1 = SensorValue[S1];
	while(!getButtonPress(buttonRight))sleep(1);
	int	grey1=(black1+white1 )/2;
	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(3000);

	wait1Msec(200);
	int alpha=compass.heading;

	while(SensorValue[S1]>grey1)
	{
		readSensor(&compass);
		displayBigTextLine(6, "Abs: %4d", compass.heading);
		displayBigTextLine(8, "Rel: %4d", compass.relativeHeading);
		//	sleep(10);
		int	err=alpha-compass.heading;
		u=k*(err-err/180*360);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(40);
	}


}
