#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
float eold=0,r,k1=1,k2=4,grey2,grey1,v=30,u,e;

int	black1 = SensorValue[S1];
	int	black2 = SensorValue[S2];
	while(!getButtonPress(buttonUp))sleep(1);
	int	white1 = SensorValue[S1];
	int	white2 = SensorValue[S2];
	while(!getButtonPress(buttonRight))sleep(1);
	grey1=(black1+white1 )/2;
	grey2=(black2+white2 )/2;
	motor[motorB] = 0;
	motor[motorC] = 0;
	wait1Msec(3000);


while(true)
{r=sgn(grey2-SensorValue[S2]);
	e=SensorValue[S1]-grey1;
	u=r*(k1*e+k2*(e-eold));
	eold=e;
	motor[motorB]=v+u;
	motor[motorC]=v-u;
	wait1Msec(1);
}
}
