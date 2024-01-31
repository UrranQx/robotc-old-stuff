int alpha1=0,alpha2=0,e1,e2,k1=1,k2=1,u1,u2;
task motor1()
{while(true)
	{
		e1=alpha1-nMotorEncoder[motorA];
		u1=e1*k1;
		motor[motorA]=u1;
		wait1Msec(1);
	}

}
task motor2()
{while(true)
	{
		e2=alpha2-nMotorEncoder[motorB];
		u2=e2*k2;
		motor[motorB]=u2;
		wait1Msec(1);
	}

}
task main()
{nMotorEncoder[motorA]=0;
	startTask(motor1);startTask(motor2);
	while(true)
	{
		wait1Msec(1500);
		alpha1=90;
		wait1Msec(1500);
		alpha1=0;

	}

}
