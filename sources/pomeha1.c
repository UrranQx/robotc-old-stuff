#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Color)
#pragma config(Motor,  motorB,          mB,            tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,          mC,            tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	float k=1.5, v=30, u, grey=32;
	while(true)
	{
		nMotorEncoder[motorB]=0;
		while(nMotorEncoder[motorB]<1700)
		{
			u=k*(SensorValue[S1]-grey);
			motor[motorB]=v+u;
			motor[motorC]=v-u;
			wait1Msec(1);
		}
		motor[motorB]=motor[motorC]=0;
		wait1Msec(1);
		nMotorEncoder[motorB]=0;
		while(nMotorEncoder[motorB]>-1600)
		{
			u=k*(SensorValue[S2]-grey);
			motor[motorB]=-(v+u);
			motor[motorC]=-(v-u);
			wait1Msec(1);
		}


	}
}
