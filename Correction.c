void correction()
{
	int v=60,k1=-5,l=10,l2=10;//l-lenght
	clearTimer(T1);
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<10)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (sensorValue[S1]>10)
			{v=k1*(SensorValue[S1]-l2);}
			else
			{v=0;}
		}
		motor[motorB]=motor[motorC]=v;
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
