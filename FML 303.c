#pragma config(Sensor, S1,     ,               sensorLightActive)
#pragma config(Sensor, S2,     ,               sensorLightActive)
#pragma config(Sensor, S3,     ,               sensorEV3_IRSensor)
#pragma config(Sensor, S4,     ,               sensorEV3_Color, modeEV3Color_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void move1()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = -50;
	while(nMotorEncoder[motorB]<180);//left//
		motor[motorB]=motor[motorC]=0;
	wait1Msec(500);


	nMotorEncoder[motorB] = 0;
	motor[motorB] = 30;
	motor[motorC] = 47;
	while(nMotorEncoder[motorB]<400);
	nMotorEncoder[motorB] = 0;
	motor[motorB] = 30;
	motor[motorC] = 49;
	while(nMotorEncoder[motorB]<780);

	nMotorEncoder[motorB] = 0;
	motor[motorB] = 50;
	motor[motorC] = -50;
	while(nMotorEncoder[motorB]<75);//left//

	wait1Msec(100);
}
task main()
{
	float u,v,es,eold,e,k1=3.1,k2=3.2,n=1,count=0;
	es = SensorValue[S1]-SensorValue[S2];
	eold = 0;

	int	black1 = SensorValue[S1];//calibr
	int	black2 = SensorValue[S2];
	while(!getButtonPress(buttonUp))sleep(1);
	int	white1 = SensorValue[S1];
	int	white2 = SensorValue[S2];
	while(!getButtonPress(buttonDown))sleep(1);
	int	grey1=(black1+white1 )/2;
	int	grey2=(black2+white2 )/2;
	motor[motorB] = 0;
	motor[motorC] = 0;
	while(!getButtonPress(buttonEnter))sleep(1);
	wait1Msec(3000);


	nMotorEncoder[motorB]=0;

	motor[motorB]=70;
	motor[motorC]=70;
	while(nMotorEncoder[motorB]<440);//out of box
		wait1Msec(100);


	while(true)
	{displayBigTextLine(4,"%d",u);
		if(n==1)
		{
			if(SensorValue[S3]>19)
			{
				e = SensorValue[S1]-SensorValue[S2]-es;//cat Doging
				u = k1*e+k2*(e-eold);
				eold = e;
				v = 60-abs(u)*0.001;
				motor[motorB] = v+u;
				motor[motorC] = v-u;
				wait1Msec(1);
			}
			else
			{
				motor[motorB] = 0;
				motor[motorC] = 0;
				wait1Msec(100);

				move1();
				n=n+1;

			}
		}
		else


		if(n==2)
		{




			//recrep
			clearTimer(T1);
			while(count<1)
			{
				if(SensorValue[S1]<grey1 && SensorValue[S2]<grey2 &&time1[T1]>120)
				{count++;
					playSound(soundBlip);
					clearTimer(T1);

				}
				e = SensorValue[S1]-SensorValue[S2]-es;
				u = k1*e+k2*(e-eold);
				eold = e;
				v = 60-abs(u)*0.01;
				motor[motorB] = v+u;
				motor[motorC] = v-u;
				wait1Msec(1);


			}
			nMotorEncoder[motorB] = 0;
			motor[motorB] = 50;
			motor[motorC] = -50;
			while(nMotorEncoder[motorB]<90);//left//
				motor[motorB]=70;
			motor[motorC]=70;
			while(nMotorEncoder[motorB]<2000);//out of box
				motor[motorB] = 0;
			motor[motorC] = 0;
			wait1Msec(1000);
		}n=n+1;

		if(n==3)

		{


			nMotorEncoder[motorB] = 0;
			motor[motorB] = 50;
			motor[motorC] = -50;
			while(nMotorEncoder[motorB]<41);//left//

		}

	}


}
