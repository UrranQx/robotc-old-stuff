#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Gyro)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
float wk=0.5,W=30;
int angle = 0;
int V1=30, green=3, mas[100], len=0,alpha=89,beta=85 ;
int fd=1;
task screen()
{
	while(true)
	{
		int Screen1=SensorValue[S1];
		int Screen2=SensorValue[S2];
		int angle=SensorValue[S3];
		displayBigTextLine(2,"Do stenkie1=%d",Screen1);
		displayBigTextLine(4,"Do stenkie2=%d",Screen2);
		displayBigTextLine(6,"UR angle is=%d",angle);
		sleep(1);
	}
}
task M()
{
	while (true)
	{
		playTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
	}
}

void correction()
{
	int v=60,k=2,u;
	int k1=-5,l=5,l2=2;//l-lenght
	clearTimer(T1);
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<5)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (SensorValue[S1]>4&&SensorValue[S1]<25)
			{v=k1*(SensorValue[S1]-l2);}
			else
			{v=0;}
		}
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
}
void l_gyro()
{
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	motor[motorB]=-W*wk;
	motor[motorC]=W*wk;
	angle=angle-beta;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait1Msec(100);
	correction();
	if(fd==1) mas[len++]=3;
}
void r_gyro()
{
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	angle=angle+alpha;
	motor[motorB]=W*wk;
	motor[motorC]=-W*wk;
	while (SensorValue[S3]<angle)//;
		motor[motorB]=motor[motorC]=0;wait1Msec(100);
	if(fd==1) mas[len++]=2;
}
/*clearTimer(T1);
while(time1[T1]<500)
{ int eg=angle+getGyroDegrees(S3);
int kgyro=1;
int u=eg*kgyro;


motor[motorB]=u;//-W*wk;
motor[motorC]=-u;//W*wk;
}
motor[motorB]=motor[motorC]=0;wait1Msec(1000);
}
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
*/
void turnback ()
{

	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	motor[motorB]=-W*wk;
	motor[motorC]=W*wk;
	angle=angle-beta*2;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait1Msec(100);

}
void Sync_forward()
{
	int v=-50,k=2,u;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while (nMotorEncoder[motorB]>-615)
	{
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
	correction();
	wait10Msec(10);
	if(fd==1)
	{mas[len++]=1;
		if(SensorValue[S4]<=green)
		{fd=0;}
	}
}

task main()
{
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	startTask (screen);
	//startTask (M);
	while(true)
	{if (fd<1) break;
		if(SensorValue[S2]>15)
		{r_gyro();Sync_forward();}
		else
		{
			if(SensorValue[S1]>15)
			{Sync_forward();}
			else
			{l_gyro();}
		}
	}
if(fd==0)
{playSound(soundException);wait1Msec(100);
	turnback();
}
}
