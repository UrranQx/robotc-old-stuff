#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     ,               sensorEV3_Gyro)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
int angle = 0;
int V1=30;
task screen()
{
	while(true)
	{
		int Screen1=SensorValue[S1];
		displayBigTextLine(2,"Do stenkie=%d",Screen1);
		sleep(10);
	}
}

task M()
{

	while (true)
	{
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  880,    7); wait1Msec(  75);  // Note(D, Duration(32th))
		PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(32th))
		PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(32th))
		PlayTone( 1047,    7); wait1Msec(  75);  // Note(F, Duration(32th))
		PlayTone( 1109,    7); wait1Msec(  75);  // Note(F#, Duration(32th))
		PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(32th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(    0,   27); wait1Msec( 300);  // Note(Rest, Duration(Eighth))
		PlayTone( 1047,   14); wait1Msec( 150);  // Note(F, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1109,   14); wait1Msec( 150);  // Note(F#, Duration(16th))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  880,  108); wait1Msec(1200);  // Note(D, Duration(Half))
		PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  831,  108); wait1Msec(1200);  // Note(C#, Duration(Half))
		PlayTone(    0,    7); wait1Msec(  75);  // Note(Rest, Duration(32th))
		PlayTone( 1398,   14); wait1Msec( 150);  // Note(A#, Duration(16th))
		PlayTone( 1175,   14); wait1Msec( 150);  // Note(G, Duration(16th))
		PlayTone(  784,  108); wait1Msec(1200);  // Note(C, Duration(Half))
		PlayTone(    0,   14); wait1Msec( 150);  // Note(Rest, Duration(16th))
		PlayTone(  932,   14); wait1Msec( 150);  // Note(A#5, Duration(16th))
		PlayTone(  784,   14); wait1Msec( 150);  // Note(C, Duration(16th))

	}
}
void correction()
{
	int v=60,k=2,u;
	int k1=-5,l=10,l2=5;//l-lenght
	clearTimer(T1);
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while(time1[T1]<1000)
	{
		if(SensorValue[S1]<10)
		{v=k1*(SensorValue[S1]-l);}
		else
		{if (SensorValue[S1]>10&&SensorValue[S1]<25)
			{v=k1*(SensorValue[S1]-l2);}
			else
			{v=0;}
		}
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
}

void R ()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB]=V1;
	motor[motorC]=-V1;
	while(nMotorEncoder[motorB]<185);

	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
}
void L ()
{
	nMotorEncoder[motorB] = 0;
	motor[motorB]=-V1;
	motor[motorC]=V1;
	while(nMotorEncoder[motorB]>- 190);

	sleep(1);motor[motorB]=motor[motorC]=0;wait10Msec(100);
}
void reset ()
{
	resetGyro(S3);
	angle=SensorValue[S3];
}
void r_gyro()
{
	motor[motorB]=30;
	motor[motorC]=-30;
	angle=angle+90;
	while (SensorValue[S3]<angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;wait10Msec(100);

}

void l_gyro()
{
	motor[motorB]=-30;
	motor[motorC]=30;
	angle=angle-90;
	while (SensorValue[S3]>angle)
		sleep(1);
	motor[motorB]=motor[motorC]=0;correction();wait10Msec(100);

}
void Sync_forward()
{
	int v=-50,k=2,u;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	while (nMotorEncoder[motorB]>-550)
	{
		int e2=nMotorEncoder[motorB];
		int e3=nMotorEncoder[motorC];
		u=k*(e3-e2);
		motor[motorB]=v+u;
		motor[motorC]=v-u;
		wait1Msec(1);
	}
	motor[motorB]=motor[motorC]=0;
	correction();
	wait10Msec(100);
}






task main()
{

	resetGyro(S3);
	sleep(200);
	angle=SensorValue[S3];
	startTask (screen);
	//startTask (M);
	while(true)
	{
		if(SensorValue[S2]>15)
		{r_gyro();Sync_forward();}
		else
		{
			if(SensorValue[S1]>15)
			{Sync_forward();}
			else
			{l_gyro();}
		}
	}
}
