
task main()
{
	  int white=SensorValue[S1];
	  while (true)
	  	{
	  		 clearTimer(T1);
	  		 motor[motorB]=motor[motorC]=100;
	  		 while(SensorValue[S1]>white-5);
	  		 int t=Time1(T1);
	  		 ClearTimer(T1);
	  		 motor[motorB]=motor[motorC]=-100;
	  		 while(time1(T1)<t);

	  		 }



}
