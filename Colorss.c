#pragma config(Sensor, S1,     ,               sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S2,     ,               sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()

{	float yellow,red,blue,black;
		displayBigTextLine(10,"%d",	SensorValue[S1]);
yellow = SensorValue[S1];
	while(!getButtonPress(buttonDown))sleep(1);
	displayBigTextLine(2,"%d",yellow);
	wait1Msec(100);

		red = SensorValue[S1];
	while(!getButtonPress(buttonUp))sleep(1);
	displayBigTextLine(4,"%d",red);
	wait1Msec(100);



		blue = SensorValue[S1];
	while(!getButtonPress(buttonLeft))sleep(1);
	wait1Msec(100);
	displayBigTextLine(6,"%d",	blue);

		black = SensorValue[S1];
	while(!getButtonPress(buttonRight))sleep(1);
	displayBigTextLine(8,"%d",black);
	wait1Msec(100);
	wait1Msec(10000);
	if (SensorValue[S1]<=Red&&SensorValue[S1]>Yellow)
	{
		PlaySound(soundDownwardTones);
		wait1Msec(400);
	}
}