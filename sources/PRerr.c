#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()

{

	int e;
	int es;
	int u;
	int v=-18;
	int k1=1.1;

	es = SensorValue[S1]-SensorValue[S2];
	while(true)
	{
		e = SensorValue[S1]-SensorValue[S2]-es;
		u=k1*e;
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);

	}


}
