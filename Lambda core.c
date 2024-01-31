#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Gyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int V1=30;
int angle = 0;
void R ()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB]=V1;
	motor[motorC]=-V1;
	while(nMotorEncoder[motorB]<185);

	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
}
void L ()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB]=-V1;
	motor[motorC]=V1;
	while(nMotorEncoder[motorB]>- 190);

	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
}
void forward ()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB]=motor[motorC]=V1;
	while(nMotorEncoder[motorB]<620);

	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
}

task main()


{

	motor[motorB]=motor[motorC]=0;
	wait10Msec(100);
	L();
	motor[motorB]=motor[motorC]=0;

	R();


}