#pragma config(Sensor, S3,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int angle = 0;
task main()
{
	///
	resetGyro(S3);
	sleep(200);
	angle=SensorValue[S3];
	///
	int V1=30;
nMotorEncoder[motorB] = 0;
	motor[motorB]=V1;
	motor[motorC]=-V1;
	angle=angle+90;
	while(nMotorEncoder[motorB]<185||SensorValue[S3]<angle);
	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);



}
