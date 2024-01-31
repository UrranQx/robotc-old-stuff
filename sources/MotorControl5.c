int alpha=0,beta=0;
task motor1()
{float a=0,b=0,ka=1,kb=1,da=1,db=1,e1,e2;
	while(true)
	{
		e1=nMotorEncoder[motorA];
		e2=nMotorEncoder[motorB];
		a=a+sgn(alpha-a)*da;
		b=b+sgn(beta-b)*db;
		motor[motorA]=ka*(a-e1);
		motor[motorB]=kb*(b-e2);
		wait10Msec(10);
	}

}
task main()
{nMotorEncoder[motorA]=0;
	nMotorEncoder[motorB]=0;
	startTask(motor1);
	while(true)
	{
		wait1Msec(250);
		alpha=45;beta=45;
		wait1Msec(250);
		alpha=0;
		wait1Msec(250);
		beta=0;






	}

}
