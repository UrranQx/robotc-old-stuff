#pragma config(Sensor, S1,     Gyro,           sensorEV3_Gyro)
#pragma config(Motor,  motorB,          motorRight,    tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,          motorLeft,     tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{int angle=SensorValue[Gyro];
	while(true)
		 {
		   motor[motorLeft]=80;
		   motor[motorRight]=-80;
		   angle=angle+86;
		   while(SensorValue[Gyro]<angle);
		    sleep(1);
		    motor[motorLeft]=80;
		    motor[motorRight]=80;
		    sleep(500);
		  }



}
