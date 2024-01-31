
task main()
{int ko=0.0005,dT=10;
	/////
	wait1Msec(500);
	float gyroOffset = 0;
	int gyroRate, gyroRateOld=0;
	float offset;
	float angVel;
	/////
	for( int i=0;i<20;i++)
	{
		gyroRate= getGyroRate(S2);
		if(gyroRate != gyroRateOld) i=0;
		gyroRateOld= gyroRate;
		wait1Msec(15);
		displayBigTextLine(1,"rate%f",gyroRate);

	}
	gyroOffset=gyroRate;
	displayBigTextLine(5,"offset%f",gyroOffset);
	wait1Msec(100000);
	/////
	offset=offset*ko+gyroRate*(1-ko);
	angVel=gyroRate-offset;
	int angle;
	angle=angle+gyroRate*(dT*0.001);
	/////
	float k3=0.7,encVel,k4=0.05,k1=0.5,k2=1;
	int enc,encOld=0,u;
	enc=(nMotorEncoder[motorB]+nMotorEncoder[motorC])/2;
	encVel=(enc-encOld)/(0.001*dT);
	encOld=enc;//oder;
	u=angVel*k1+angle*k2-enc*k3+encVel*k4;
	/////
	/*
	int delta=50;
int 	a=sgn(u-motor[motorB])*delta;
	if(abs(u-motor[motorB])<delta)
	{
		motor[motorB]=motor[motorC]=u;
	}
	else
	{
		motor[motorB]=motor[motorB]+a;
		motor[motorC]=motor[motorC]+a;
	}
	/////
	int m_B,m_C;
	float mBSoft=0,mCSoft=0,kMSoft=0.9;
	{
		m_B=u;
		m_C=u;
		mBSoft=mBSoft*kMSoft+m_B*(1-kMSoft);
		mCSoft=mCSoft*kMSoft+m_C*(1-kMSoft);
		motor[motorB]=mBSoft;
		motor[motorC]=mCSoft;
	}
	/////
	int velocity=10;
	float path=0;
	while(true)
	{

		path=path+(velocity*dT*0.0001);
		u=angVel*k1+angle*k2+(enc+path)*k3+encVel*k4;

	}
	*/
	motor[motorB]=u;
	motor[motorC]=u;
}
