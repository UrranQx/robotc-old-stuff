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
	while(nMotorEncoder[motorB]<185);
	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
	while(SensorValue[S3]==angle+90)
	{
		if(SensorValue[S3]>angle+90)
		{
			motor[motorB]=-30;
			motor[motorC]=30;
		}
		else
		{
			motor[motorB]=30;
			motor[motorC]=-30;
		}

	}
	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);

}
