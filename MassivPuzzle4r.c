#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Gyro)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
float wk=0.5,W=30;
int angle = 0;
int V1=30, green=3, mas[100], len=0,alpha=86,beta=-85 ;
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
	angle=angle+beta;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait1Msec(100);
	correction();
	if(fd) mas[len++]=3;
}
void r_gyro()
{
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	angle=angle+alpha;
	motor[motorB]=W*wk;
	motor[motorC]=-W*wk;
	while (SensorValue[S3]<angle);
	motor[motorB]=motor[motorC]=0;wait1Msec(100);
	if(fd) mas[len++]=2;
}

void turnback ()
{


}
void Sync_forward()
{
	int v=-50,k=2,u;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while (nMotorEncoder[motorB]>-615)//old615
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
	if(fd)
	{
		mas[len++]=1;
		if(SensorValue[S4]<=green)
		{fd=0;}
	}
}
void PTH()
{
	for(int i=0;i<len;i++)
		switch(mas[i])
{case 0: playSound(soundBeepBeep); break;
	case 1: Sync_forward(); break;
		//	case 2: r_gyro();break;
		//	case 3: l_gyro();break;
	case 2: l_gyro();break;
	case 3: r_gyro();break;
	}
}
task main()
{ for (int i=0;i<len;i++)
		mas[i]=0;
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	startTask (screen);
	//startTask (M);
	while(fd)
	{resetGyro(S3);
		if(SensorValue[S2]>15)
		{resetGyro(S3);r_gyro();Sync_forward();
		}
		else
		{
			if(SensorValue[S1]>15)
			{Sync_forward();}
			else
			{resetGyro(S3);l_gyro();}
		}
	}
	playSound(soundException);wait1Msec(500);

	l_gyro();l_gyro();

	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(1000);

	PTH();

}
