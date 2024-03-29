#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_Reflected_Raw)
#pragma config(Sensor, S2,     ,               sensorEV3_Color, modeEV3Color_Reflected_Raw)
#pragma config(Sensor, S3,     ,               sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void move1()
{	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = -50;
	while(nMotorEncoder[motorB]<140);//right//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]<200);//forward//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = -50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]>-117);//left//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]<750);//forward//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = -50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]>-117);//left//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = 50;
	while(nMotorEncoder[motorB]<210);//forward//
		wait1Msec(100);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = -50;
	while(nMotorEncoder[motorB]<155);//right//
		wait1Msec(100);
}
task main()
{float u,v,es,eold,e,k1=4.8,k2=8.9;
	int green1 = SensorValue[S1];
	while(!getButtonPress(buttonUp))Sleep(1);

	int green2 = SensorValue[S2];
	while(!getButtonPress(buttonLeft))Sleep(1);

	int black1 = SensorValue[S1];
	int black2 = SensorValue[S2];
	while(!getButtonPress(buttonRight))Sleep(1);

	int white1 = SensorValue[S1];
	int white2 = SensorValue[S2];
	while(!getButtonPress(buttonDown))Sleep(1);

	wait1Msec(1000);

	es = SensorValue[S1]-SensorValue[S2];
	eold = 0;
	while(true)
	{

		if(SensorValue[S1]>green1&&SensorValue[S2]>green2&&SensorValue[S1]<black1 &&SensorValue[S2]<black2)
		{//<white
			//return180
			nMotorEncoder[motorB] = 0;
			motor[motorB] = 50;
			motor[motorC] = -50;
			while(nMotorEncoder[motorB]<205);
			wait1Msec(100);


			motor[motorB] = 0;
			motor[motorC] = 0;

			wait1Msec(100);
		}

		if(SensorValue[S1]>green1 && SensorValue[S1]<black1)
		{//returnLeft;
			nMotorEncoder[motorB] = 0;
			motor[motorB] = -50;
			motor[motorC] = 50;
			while(nMotorEncoder[motorB]>-155);
			wait1Msec(100);
			motor[motorB] = 0;
			motor[motorC] = 0;

			wait1Msec(100);

		}
		if(SensorValue[S2]<=green2 && SensorValue[S2]<black2)
		{	nMotorEncoder[motorB] = 0;
			motor[motorB] = 50;
			motor[motorC] = -50;
			while(nMotorEncoder[motorB]<155);//right//
				wait1Msec(100);
			motor[motorB] = 0;
			motor[motorC] = 0;

			wait1Msec(100);
			//returnRight;

		}
		//moving

		if(SensorValue[S3]>10)//10
		{

			if(SensorValue[S1]>green1 && SensorValue[S1]<black1)
			{//returnLeft;
				nMotorEncoder[motorB] = 0;
				motor[motorB] = -50;
				motor[motorC] = 50;
				while(nMotorEncoder[motorB]>-155);
				wait1Msec(100);
				motor[motorB] = 0;
				motor[motorC] = 0;

				wait1Msec(100);

			}
			if(SensorValue[S2]<=green2 && SensorValue[S2]<black2)
			{	nMotorEncoder[motorB] = 0;
				motor[motorB] = 50;
				motor[motorC] = -50;
				while(nMotorEncoder[motorB]<155);//right//
					wait1Msec(100);
				motor[motorB] = 0;
				motor[motorC] = 0;

				wait1Msec(100);
				//returnRight;

			}
			e = SensorValue[S1]-SensorValue[S2]-es;
			u = k1*e+k2*(e-eold);
			eold = e;
			v = 30-abs(u)*0.001;
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
