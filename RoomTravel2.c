#pragma config(Sensor, S4,     Ultrasonic,     sensorEV3_Ultrasonic)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{while(true)
 {

 motor[motorB]=100;
 motor[motorC]=100;
 while(SensorValue[Ultrasonic]>30)

{displayBigTextLine(2,"%d",SensorValue[Ultrasonic]);
   sleep(100)
}
 sleep(1);
 motor[motorB]=-50;
 motor[motorC]=-10;
 nMotorEncoder[motorB]=0;

 {displayBigTextLine(6,"%d",nMotorEncoder[motorB]);
   sleep(100);
 }
 while(nMotorEncoder[motorB]>-400)
   sleep(1);
}




}
