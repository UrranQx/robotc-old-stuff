#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{float u,v,es,eold,e,k1=1.4,k2=2.6,count=0;
	int	black1 = SensorValue[S1];
	int	black2 = SensorValue[S2];
	while(!getButtonPress(buttonUp))sleep(1);
	int	white1 = SensorValue[S1];
	int	white2 = SensorValue[S2];
	while(!getButtonPress(buttonRight))sleep(1);
	int	grey1=(black1+white1 )/2;
	int	grey2=(black2+white2 )/2;
	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(3000);
	es = SensorValue[S1]-SensorValue[S2];
	eold = 0;
	while(count<7)
	{
if(SensorValue[S1]<grey1 && SensorValue[S2]<grey2)
{count++;
		PlaySound(soundDownwardTones);

}
		e = SensorValue[S1]-SensorValue[S2]-es;
		u = k1*e+k2*(e-eold);
		eold = e;
		v = 50-abs(u)*0.001;
		motor[motorB] = v+u;
		motor[motorC] = v-u;
		wait1Msec(1);


	}

}