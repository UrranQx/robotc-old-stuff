
task main()
{
	motor[motorB]=100;
	motor[motorC]=100;
	wait1Msec(2000);

	motor[motorB]=-100;
	motor[motorC]=100;
	nMotorEncoder[motorB]=0;
	while(nMotorEncoder[motorB]>-330)sleep(1);
	motor[motorB]=0;
	motor[motorC]=0;



}
