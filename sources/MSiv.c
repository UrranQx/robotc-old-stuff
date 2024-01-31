float wk=0.5,W=30;
int angle = 0;
int V1=30;
int mas[12]={1,2,1,1,3,1,1,2,1,1,3,1};
int len=12;
void correction()
{
	int v=60,k=2,u;
	int k1=-5,l=5,l2=5;//l-lenght
	clearTimer(T1);
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<5)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (SensorValue[S1]>4&&SensorValue[S1]<25)
			{v=k1*(SensorValue[S1]-2);}
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
	angle=angle-85;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait1Msec(100);
	correction();

}
void r_gyro()
{
	resetGyro(S3);
	sleep(100);
	angle=SensorValue[S3];

	angle=angle+90;
	motor[motorB]=W*wk;
	motor[motorC]=-W*wk;

	while (SensorValue[S3]<angle);

	motor[motorB]=motor[motorC]=0;wait1Msec(100);}

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
}
void PTH(){
for(int i=0;i<len;i++)
	switch(mas[i])
{
case 1: Sync_forward(); break;
case 2: r_gyro();break;
case 3: l_gyro();
}
}

task main()
{
PTH();


}
