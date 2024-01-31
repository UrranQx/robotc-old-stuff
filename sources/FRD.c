
task main()
{

	nMotorEncoder[motorB] = 0;
		motor[motorB] = 50;
		motor[motorC] = 50;
		while(nMotorEncoder[motorB]<2805);//left//

		wait1Msec(100);

}
