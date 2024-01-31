
task main()
{
	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]>-340)
	{motor[motorA]=-10;
		wait1Msec(100);
	}
	motor[motorA]=0;
	wait1Msec(1000);

	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=10;
		wait1Msec(100);
	}


	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]>-340)
	{motor[motorA]=-20;
		wait1Msec(100);
	}
	motor[motorA]=0;
	wait1Msec(900);

	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=20;
		wait1Msec(100);
	}
	nMotorEncoder[motorA]=0;




	while(nMotorEncoder[motorA]>-340)
	{motor[motorA]=-25;
		wait1Msec(100);
	}
	motor[motorA]=0;
	wait1Msec(800);

	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=25;
		wait1Msec(100);
	}




	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]>-340)
	{motor[motorA]=-80;
		wait1Msec(100);
	}
	motor[motorA]=0;
	wait1Msec(50);

	nMotorEncoder[motorA]=0;

	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=80;
		wait1Msec(100);
	}


}
