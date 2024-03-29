#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Color)
#pragma config(Sensor, S3,     ,               sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void move1()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB] = -50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]>-180);//right//
		motor[motorB]=motor[motorC]=0;
	wait1Msec(500);

	if (SensorValue[S3]>10)
	{


		nMotorEncoder[motorB] = 0;
		motor[motorB] = 57;
		motor[motorC] = 30;
		while(nMotorEncoder[motorB]<700);

		nMotorEncoder[motorB] = 0;
		motor[motorB] = 47;
		motor[motorC] = 30;
		while(nMotorEncoder[motorB]<800);


		nMotorEncoder[motorB] = 0;
		motor[motorB] = -50;
		motor[motorC] = 50;
		while(nMotorEncoder[motorB]>-180);//right//
			wait1Msec(100);




	}
	else
	{//Left manuevor

		nMotorEncoder[motorB] = 0;
		motor[motorB] = 50;
		motor[motorC] = -50;
		while(nMotorEncoder[motorB]<290);//right//
			wait1Msec(100);

		nMotorEncoder[motorB] = 0;
		motor[motorB] = 30;
		motor[motorC] = 57;
		while(nMotorEncoder[motorB]<300);
		motor[motorB]=motor[motorC]=0;
		wait1Msec(5);
		nMotorEncoder[motorB] = 0;
		motor[motorB] = 36;
		motor[motorC] = 42;
		while(nMotorEncoder[motorB]<100);
		nMotorEncoder[motorB] = 0;
		motor[motorB] = 28;
		motor[motorC] = 50;
		while(nMotorEncoder[motorB]<400);



		nMotorEncoder[motorB] = 0;
		motor[motorB] = 50;
		motor[motorC] = -50;
		while(nMotorEncoder[motorB]<90);//left//

		wait1Msec(100);


	}
}
task main()
{float u,v,es,eold,e,k1=7.7,k2=10;
	ClearTimer(T1);
	int	silver1=20
	es = SensorValue[S1]-SensorValue[S2];
	eold = 0;
	while(SensorValue[S1]<=silver1 && SensorValue[S2]<=silver1 && time1[T1]<100)
	{displayBigTextLine(4,"%d",u);

		if(SensorValue[S3]>6)
		{
			e = SensorValue[S1]-SensorValue[S2]-es;
			u = k1*e+k2*(e-eold);
			eold = e;
			v = 40-abs(u)*0.001;
			motor[motorB] = v+u;
			motor[motorC] = v-u;
			wait1Msec(1);
		}
		else
		{
			motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(100);

			move1();

		}ClearTimer(T1);


	}


}
