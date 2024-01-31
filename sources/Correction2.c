void correction()
{
	int v=60,k=2,u;
	int k1=-5,l=10,l2=5;//l-lenght
	clearTimer(T1);
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<10)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (SensorValue[S1]>10&&SensorValue[S1]<25)
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

/*void forward ()
...PlaySound(...);
correction();
*/
task main
{
	correction();

}
