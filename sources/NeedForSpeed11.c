#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	int alpha=0;
	int v=-100;
	int k=2;
	int e;
	int a;
	int da=2;
	int count=0;
	float grey3=9;

	motor[motorA]=-15;
	sleep(500);
	motor[motorA]=0;
	nMotorEncoder[motorA]=0;

	while(SensorValue[S2]>15)
		sleep(1);
	clearTimer(T1);

	while(count<14)
	{
		if(SensorValue[S1]<grey3 &&time1[T1]>400)
		{count++;
			playSound(soundBlip);
			clearTimer(T1);

		}

		e=SensorValue[S2]-SensorValue[S3];
		if (abs(e)>100)//...>100
			alpha=50+sgn(e)*50;//alpha = 50+...
		else
			alpha=50+e/2;
		a=a+sgn(alpha-a)*da;
		motor[motorA]=k*(a-nMotorEncoder[motorA]);
		motor[motorB]=-v;
		sleep(1);

	}
}
