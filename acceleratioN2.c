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
void bzz2()
{float deg=20,q=900;
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
void bzz3()
{float deg=25,q=830;
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
void bzz4()
{float deg=34,q=790;
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
void bzz5()
{float deg=40,q=700;
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
void bzz6()
{float deg=44,q=650;
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
void bzz7()
{float deg=50,q=410;
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
void bzz8()
{float deg=55,q=360;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-320)
	{motor[motorA]=-1*(deg);
		wait1Msec(100);}
	motor[motorA]=0;
	wait1Msec(q);
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=1*(deg);
		wait1Msec(100);}
}
void bzz9()
{float deg=60,q=200;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-320)
	{motor[motorA]=-1*(deg);
		wait1Msec(100);}
	motor[motorA]=0;
	wait1Msec(q);
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=1*(deg);
		wait1Msec(100);}
}
void bzz10()
{float deg=70,q=10;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-320)
	{motor[motorA]=-1*(deg);
		wait1Msec(100);}
	motor[motorA]=0;
	wait1Msec(q);
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=1*(deg);
		wait1Msec(100);}
}
void bzz11()
{float deg=100,q=0;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-320)
	{motor[motorA]=-1*(deg);
		wait1Msec(100);}
	motor[motorA]=0;
	wait1Msec(q);
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]<330)
	{motor[motorA]=1*(deg);
		wait1Msec(100);}
}
		void bzz12()
{float deg=100,q=0;
	nMotorEncoder[motorA]=0;
	while(nMotorEncoder[motorA]>-320)
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
	bzz2();
	bzz3();
	bzz4();
	bzz5();
	bzz6();
	bzz7();
	bzz8();
	bzz9();
	bzz10();
	bzz11();
	bzz12();
}
