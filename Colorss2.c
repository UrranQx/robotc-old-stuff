#pragma config(Sensor, S1,     ,               sensorEV3_Color)
#pragma config(Sensor, S2,     ,               sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()

{	float yellow,red,blue,black;
	displayBigTextLine(10,"%d",	SensorValue[S1]);
	yellow = SensorValue[S1];
	while(!getButtonPress(buttonDown))sleep(1);

	wait1Msec(100);

	red = SensorValue[S1];
	while(!getButtonPress(buttonUp))sleep(1);
	wait1Msec(100);

	displayBigTextLine(10,"%d",	SensorValue[S1]);

	blue = SensorValue[S1];
	while(!getButtonPress(buttonLeft))sleep(1);
	wait1Msec(100);
	displayBigTextLine(10,"%d",	SensorValue[S1]);

	black = SensorValue[S1];
	while(!getButtonPress(buttonRight))sleep(1);
	wait1Msec(100);
	displayBigTextLine(10,"%d",	SensorValue[S1]);
	wait1Msec(5000);
	while (true)

	{


		if (SensorValue[S1]>=yellow-5)
		{
			displayBigTextLine(2,"yellow=%d",	yellow);
			wait1Msec(1000);
		}

		else if(SensorValue[S1]>=red-5)
		{
			displayBigTextLine(4,"red=%d",	red);
			wait1Msec(1000);
		}

		else if(SensorValue[S1]>=blue-30)
		{
			displayBigTextLine(6,"blue=%d",	blue);
			wait1Msec(1000);
		}
		else if(SensorValue[S1]>=black-5)
		{
			///black
			displayBigTextLine(8,"black=%d",	black);
			wait1Msec(1000);
		}

	}

}
