#pragma config(Sensor, S1,     ,               sensorEV3_Color)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{ int white=SensorValue[S1];
	while (true){
		motor[motorB]=-100;
		motor[motorC]=-100;
		while(SensorValue[S1]>white-13);
		motor[motorB]=100;
		motor[motorC]=100;
		wait1Msec(500);
		motor[motorB]=-100;
		wait1Msec(600);
	}



}
