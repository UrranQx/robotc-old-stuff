
task main()
{int white=SensorValue[S1];
	while (true)
		{
			 nMotorEncoder[motorB]=0;
			 motor[motorB]=motor[motorC]=100;
			 while(SensorValue[S1]>white-5);
			 	bFloatDuringInactiveMotorPWM=true;
			 	motor[motorB]=motor[motorC]=0;
			 	while(SensorValue[S1]<white-5);
			 	bFloatDuringInactiveMotorPWM=false;
			 	motor[motorB]=motor[motorC]=-100;
			 	while(nMotorEncoder[motorC]>0);
			 		 nMotorEncoder[motorC]>0;
			 		motor[motorB]=-50;
			 		motor[motorC]=50;
			 		while(nMotorEncoder[motorC]>0);
			 		}



}
