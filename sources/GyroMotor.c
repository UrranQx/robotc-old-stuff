#pragma config(Sensor, S1,     Gyro,           sensorEV3_Gyro)
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{int angle=SensorValue[Gyro];
	while(true)
		 {
		   motor[motorLeft]=20;
		   motor[motorRight]=-20;
		   angle=angle+90;
		   while(SensorValue[Gyro]<angle);
		    sleep(1);
		    motor[motorLeft]=40;
		    motor[motorRight]=40;
		    sleep(2000);
		  }



}
