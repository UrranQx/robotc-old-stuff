int alpha1=0,alpha2=0,e1,e2,k1=2,k2=2,u1,u2;
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
	nMotorEncoder[motorB]=0;
	startTask(motor1);startTask(motor2);
	while(true)
	{
		wait1Msec(250);
		alpha1=23;alpha2=0;
		wait1Msec(250);
		alpha1=0;alpha2=27;
			wait1Msec(100);alpha2=0;
		wait1Msec(250);
		alpha1=23;alpha2=25;
		wait1Msec(250);
		alpha1=0;alpha2=0;


	}

}
