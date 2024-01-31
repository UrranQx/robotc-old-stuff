void correctionPI()
{
	int v=60,k=5,l=5,imax=20,p;//l-lenght
	float i=0,ki=0.02,kp=1;
	clearTimer(T1);
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<15)
		{
			int e= SensorValue[S1]-l;
			p=kp*e;
			i=i+ki*e;
			if(abs(i)>imax) i=sgn(i)*imax
				v=p+i;

		}
		else
		{v=0;}
		motor[motorB]=motor[motorC]=v;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
}

/*void forward ()
...PlaySound(...);
correctionPI();
*/
