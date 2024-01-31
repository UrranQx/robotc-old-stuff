#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int W=30;float wk=0.5,k2=0.5;
task screen()
{
	while(true)
	{
		int Screen1=SensorValue[S1];int Screen2=SensorValue[S2];int angle=SensorValue[S3];
			//displayBigTextLine(2,"Do stenkie1=%d",Screen1);	displayBigTextLine(4,"Do stenkie2=%d",Screen2);
		displayBigTextLine(6,"UR angle is=%d",angle);
		sleep(1);
	}
}
int angle = 0;
void l_gyro()
{	resetGyro(S3);//
	sleep(100);
	angle=SensorValue[S3];
	motor[motorB]=-W;
	motor[motorC]=W;
	angle=angle-90;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait1Msec(1000);


}
void r_gyro()
{
	resetGyro(S3);//
	sleep(100);

	angle=SensorValue[S3];
	angle=angle+90;
	motor[motorB]=W*wk;
	motor[motorC]=-W*wk;

	while (SensorValue[S3]<angle);

	motor[motorB]=motor[motorC]=0;wait1Msec(1000);
	displayBigTextLine(1,"UR angle is=%d",angle);displayBigTextLine(3,"UR S3 is=%d",SensorValue[S3]);
	wait1Msec(5000);
	while (SensorValue[S3]<-angle)
	{	motor[motorB]=-W*k;
		motor[motorC]=W*k;
	}

}
task main()
{//startTask(screen);
	resetGyro(S3);
	sleep(200);
	angle=SensorValue[S3];



	r_gyro();
	wait1Msec(10000);

}