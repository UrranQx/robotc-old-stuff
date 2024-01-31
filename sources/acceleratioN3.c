void bzz1()
{float deg,q;
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
{float deg=10,q=1000;
	bzz1();
		float  deg=20;q=900;
	bzz1();
	float  	deg=25;q=830;
	bzz1();
	float 	deg=34;q=790;
	bzz1();
	float  	deg=40;q=700;
	bzz1();
float	deg=44;q=650;
	bzz1();
	float 	deg=50,q=410;
	bzz1();
	float  	deg=55;q=360;
	bzz1();
	float  	deg=60;q=200;
	bzz1();
	int 	deg=70;q=10;
	bzz1();
		float  	deg=100;q=0;
	bzz1();
	bzz1();
	bzz1();
}
