task main()
{
	int alpha=0;
	int v=100;
	int k=2;
	int e;


	motor[motorA]=-5;
	sleep(2000);
	motor[motorA]=0;
	nMotorEncoder[motorA]=0;
	playSound(soundBeepBeep);
	while(SensorValue[S1]>10)
		sleep(1);
	while(true)
	{
		e=SensorValue[S1]-SensorValue[S2];
		if (abs(e)>100)
			alpha=50+sgn(e)*50;
		else
			alpha=50+e/2;
		motor[motorA]=k*(alpha-nMotorEncoder[motorA]);
		motor[motorB]=v;
		sleep(1);
	}






}
