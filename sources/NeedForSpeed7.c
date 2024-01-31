task main()
{
	int alpha=0;
	int v=100;
	int k=2;
	int e;
	int a;
	int da=1;
int count=0;
int grey3=SensorValue[S3]-10;

	motor[motorA]=-5;
	sleep(2000);
	motor[motorA]=0;
	nMotorEncoder[motorA]=0;
	playSound(soundBeepBeep);
	while(SensorValue[S1]>10)
		sleep(1);
clearTimer(T1);
	while(true)
	{
		e=SensorValue[S1]-SensorValue[S2];
		if (abs(e)>100)
			alpha=50+sgn(e)*50;
		else
			alpha=50+e/2;
		a=a+sgn(alpha-a)*da;
		motor[motorA]=k*(a-nMotorEncoder[motorA]);
		motor[motorB]=v;
		sleep(10);
		if (SensorValue[S3]<grey3 && time1[T1]>1000)
		{
			motor[motorB]=0;
			sleep(1000);
			clearTimer(T1);
		}
	}






}
