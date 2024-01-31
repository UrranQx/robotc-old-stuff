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
	motor[motorB] = 50;
	motor[motorC] = -50;
	while(nMotorEncoder[motorB]<180);//left//
		motor[motorB]=motor[motorC]=0;
	wait1Msec(500);

	if (SensorValue[S3]>10)
	{
		nMotorEncoder[motorB] = 0;
		motor[motorB] = 30;
		motor[motorC] = 57;
		while(nMotorEncoder[motorB]<300);
		nMotorEncoder[motorB] = 0;
		motor[motorB] = 30;
		motor[motorC] = 49;
		while(nMotorEncoder[motorB]<370);

		nMotorEncoder[motorB] = 0;
		motor[motorB] = 50;
		motor[motorC] = -50;
		while(nMotorEncoder[motorB]<285);//left//

		wait1Msec(100);
	}
	else
	{//Right manuevor

		nMotorEncoder[motorB] = 0;
		motor[motorB] = 57;
		motor[motorC] = 30;
		while(nMotorEncoder[motorB]<760);//right//
			wait1Msec(100);



		nMotorEncoder[motorB] = 0;
		motor[motorB] = -50;
		motor[motorC] = 50;
		while(nMotorEncoder[motorB]>-270);//right//
			wait1Msec(100);


	}
}
task main()
{float u,v,es,eold,e,k1=7.7,k2=9;
	es = SensorValue[S1]-SensorValue[S2];
	eold = 0;
	while(true)
	{displayBigTextLine(4,"%d",u);

		if(SensorValue[S3]>6)
		{
			e = SensorValue[S1]-SensorValue[S2]-es;
			u = k1*e+k2*(e-eold);
			eold = e;
			v = 40-abs(u)*0.000000000000001;
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

		}


	}


}
