//just some balancing robot
//JSBr

#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorEV3_Gyro)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int gyroOffset,gyroRate,GyroRateOld=0,angVel;
	float angle=0;
	int dT=4;
task main()
{
		sleep(100);resetGyro(S2);sleep(100);
	for(int i=0; i<20;i++)
	{
gyroRate=getGyroRate(S2);
if(gyroRate!=GyroRateOld) i=0;
GyroRateOld=gyroRate;
sleep(15);
displayBigTextLine(1,"gyro rate=%d",getGyroRate(S2));
}
gyroOffset=gyroRate;
displayBigTextLine(5,"gyroOffset=%d",gyroOffset);

	while(true)
	{
		angVel=getGyroRate(S2)-gyroOffset;
		angle=angle+angVel*dT*0.001;
		displayBigTextLine(7,"angVel=%d",angVel);
		displayBigTextLine(7,"angle=%d",angle);
		//displayBigTextLine(3,"gyro degr=%d",getGyroDegrees(S2));
		sleep(dT);
	}
















	/////



}
