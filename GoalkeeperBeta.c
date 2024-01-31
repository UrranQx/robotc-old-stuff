#pragma config(Sensor, S2,     ,               sensorI2CCustom)
#pragma config(Sensor, S3,     HTIRS2,         sensorI2CCustom)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "hitechnic-irseeker-v2.h"
#include "hitechnic-compass.h"

task main ()
{
	float u, v=40, err, ks=0.2,e=0;
	wait1Msec(100);
	tHTMC compass;
	initSensor(&compass, S2);
	sleep(200);
	readSensor(&compass);
	compass.offset = compass.heading;
	int alpha=compass.heading;
	tHTIRS2 irSeeker;
	initSensor(&irSeeker, S3);
	int	black1 = SensorValue[S1];//calibr
	while(!getButtonPress(buttonUp))sleep(1);
	int	green1 = SensorValue[S1];
	while(!getButtonPress(buttonDown))sleep(1);
	int	grey1=(black1+green1 )/2;

	motor[motorB] = 0;
	motor[motorC] = 0;
	while(!getButtonPress(buttonEnter))sleep(1);
	wait1Msec(1000);


	while(true)
	{
		readSensor(&irSeeker);
		if (SensorValue[S1]>black1)//	if (irSeeker.acValues[2]>160)
			//readSensor(Compass)
		{                          //forward boost;
			//get back across black line;
			//repeat;



			e=alpha-compass.heading;
			e=e-(e/180)*360;
			int sector=5+ks*e/30.0;
			err=sector-irSeeker.acDirection;

			u=err*10;//;-

			int mB=v-u;
			int mC=v+u;
			if (abs(mB)>100) mB=sgn(mB)*100;
			if (abs(mC)>100) mC=sgn(mC)*100;
			motor[motorB]=mB;
			motor[motorC]=mC;
			sleep(10);

		}

		else

		{//get back & look after ball;
			motor[motorB]=motor[motorC]=0;
			wait1Msec(5);
			while(nMotorEncoder[motorB]>-271||SensorValue[S1]>black1)
			{
				nMotorEncoder[motorB] = 0;
				motor[motorB] = -67;
				motor[motorC] = -67;
			}
		}


	}

}
//}
