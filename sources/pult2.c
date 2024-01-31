void bzz1()
{float deg=10,q=1000;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-340)
	{motor[motorA]=-1*(deg);
		wait1Msec(100);}
	motor[motorA]=0;
	wait1Msec(q);
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=1*(deg);
		wait1Msec(100);}
}

task main()
{
	bzz1();
}
