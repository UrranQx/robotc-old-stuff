
task main()
{int white=SensorValue[S1];
	while (true){
		  motor[motorA]=motor[motorD]=-100
		  while(SensorValue[S1]>white-5);
		  while(SensorValue[S1]<white-5);
		  motor[motorA]=motor[motorD]=100;
		  wait1Msec(500);
		  motor[motorA]=-100;
		  wait1Msec(600);
		  }



}
