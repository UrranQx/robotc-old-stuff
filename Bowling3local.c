
task main()
{int white=SensorValue[S1];
	while (true){
		 motor[motorA]=motor[motorD]=-100;
		 while(SensorValue[S1]>white-5);
		 bFloatDuringInactiveMotorPWM=true;
		 motor[motorA]=motor[motorD]=0;
		 	while(SensorValue[S1]<white-5);
		 	bFloatDuringInactiveMotorPWM=false;
		 	motor[motorA]=motor[motorD]=100;
		 	wait1Msec(430);
		 	motor[motorA]=50;
		 	motor[motorD]=-50;
		 	wait1Msec(430);
		}



}
