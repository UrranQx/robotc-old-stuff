
task main()
{
if(SensorValue[S1]>green1&&SensorValue[S2]>green2&&SensorValue[S1]<black1 &&SensorValue[S2]<black2)
		{//<white
			//return180
			nMotorEncoder[motorB] = 0;
			motor[motorB] = 50;
			motor[motorC] = -50;
			while(nMotorEncoder[motorB]<205);
			wait1Msec(100);


			motor[motorB] = 0;
			motor[motorC] = 0;

			wait1Msec(100);
		}


}
