void forward1()
{

}
void correction()
{
	int v=60,k=2,u;
	int k1=-5,l=5,l2=2;//l-lenght
	clearTimer(T1);
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<5)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (SensorValue[S1]>4&&SensorValue[S1]<25)
			{v=k1*(SensorValue[S1]-l2);}
			else
			{v=0;}
		}
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
}
void Sync_forward2()
{	float k3=2,e,k4=3,es2old=0,u1=0;

	int v=-50,k=2,u;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while (nMotorEncoder[motorB]>-615)//old615
	{

	if (SensorValue[S2]<14)
	{
		e=SensorValue[S2]-7;
		u1=k3*e+k4*(e-es2old);
		es2old=e;
		motor[motorB]=v+u1;
		motor[motorC]=v-u1;//po stnke
		wait1Msec(1);
	}
	else {
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);}
	}
	motor[motorB]=motor[motorC]=0;
	correction();
	wait10Msec(0.1);

}
task main()
{ while (true)
{
Sync_forward();
}
}
