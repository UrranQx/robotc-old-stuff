
task main()
{
	nMotorEncoder[motorB]=0;

	motor[motorB]=70;
	motor[motorC]=70;
while(nMotorEncoder[motorB]<300);
	wait1Msec(100);

}
