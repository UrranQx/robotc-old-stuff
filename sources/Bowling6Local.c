
task main()
{int white=SensorValue[S1];
	while (true)
		{
			 nMotorEncoder[motorA]=0;
			 motor[motorA]=motor[motorD]=-100;
			 while(SensorValue[S1]>white-5);
			 	bFloatDuringInactiveMotorPWM=true;
			 	motor[motorA]=motor[motorD]=0;
			 	while(SensorValue[S1]<white-5);
			 	bFloatDuringInactiveMotorPWM=false;
			 	motor[motorA]=motor[motorD]=100;
			 	while(nMotorEncoder[motorD]>0);
			 		 nMotorEncoder[motorD]>0;
			 		motor[motorA]=50;
			 		motor[motorC]=-50;
			 		while(nMotorEncoder[motorD]>0);
			 		}



}
