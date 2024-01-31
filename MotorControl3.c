int alpha1=0,e1,u1,i=0,kp=1,ki=0.01,p;
task motor1()
{while(true)
	{
		e1=alpha1-nMotorEncoder[motorA];
		p=kp*e1;
		i=i+ki*e1;
		u1=p+i;
		motor[motorA]=u1;
		wait1Msec(1);
	}

}



task main()
{nMotorEncoder[motorA]=0;

	startTask(motor1);
	while(true)
	{
		wait1Msec(250);
		alpha1=90;
		wait1Msec(250);
		alpha1=0;



	}

}
