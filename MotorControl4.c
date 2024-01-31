
int alpha=0,beta=0,e1,e2,k1=1,k2=1,u1,u2;
task motor1()
{while(true)
	{
		e1=alpha-nMotorEncoder[motorA];
		e2=beta-nMotorEncoder[motorB];
		u1=e1*k1;		u2=e2*k2;
		motor[motorA]=u1;		motor[motorB]=u2;
		wait1Msec(1);
	}

}

task main()
{nMotorEncoder[motorA]=0;
	nMotorEncoder[motorB]=0;
	startTask(motor1);
	while(true)
	{
		wait1Msec(1000);
		alpha=90;
		beta=30;

		wait1Msec(1000);
		beta=0;
		wait1Msec(1000);
		alpha=0;
		wait1Msec(1000);
		beta=30;


	}

}
