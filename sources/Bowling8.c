#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{int white=SensorValue[S1];
	while (true)
	{
		motor[motorB]=20;
		motor[motorC]=-20;
		wait1Msec(200);
		while(SensorValue[S4]>45);
		nMotorEncoder[motorB]=0;
		motor[motorB]=motor[motorC]=50;
		while(SensorValue[S1]>white-5);
		bFloatDuringInactiveMotorPWM=true;
		motor[motorB]=motor[motorC]=0;
		wait1Msec(500);
		bFloatDuringInactiveMotorPWM=false;
		motor[motorB]=motor[motorC]=-50;
		while(nMotorEncoder[motorB]>0);
	}
}
