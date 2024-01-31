#pragma config(Sensor, S1,     ,               sensorEV3_Ultrasonic)
#pragma config(Sensor, S2,     ,               sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     ,               sensorEV3_Color)
#pragma config(Sensor, S4,     ,               sensorEV3_Color)
#pragma config(Motor,  motorB,           ,             tmotorEV3_Large, openLoop, encoder)
#pragma config(Motor,  motorC,           ,             tmotorEV3_Large, openLoop, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//just some balancing robot
//JSBr
/*
,32c#, 32e#,32c#,16g,16e,16g,16g,16f,16d,16c.
d=4,o=6,b=100:
32g,32a,32g,32e,32g,32a,32g,32e,32d,32d,32b,32c,
32c,32d,32a,32a,32c,32b,32a,32g,32a,32g,32e,32a,
32c,32b,32a,32g,32a,32g,32e,32d,32d,32f,32d,32b,
32,c,32e,32c,32g,32e,32g,32g,32f,32d,32c


32g,32a,32g,32e,32g,32a,32g,32e,32p,
32d,32d,32b,32c,32c,32g,32p,
32a,32a,32c,32b,32a,32p,
32g,32a,32g,32e,
32p,32a,32a,32c,32b,32a,32p,
32g,32a,32g,32e,32p,32d,32d,32f,32d,32b,32c,32e,
32p,32c,32g,32e,32g,32g,32f,32d,32c

*/

task xD()
{
	//        200 = Tempo
	//          6 = Default octave
	//    Quarter = Default note length
	//        10% = Break between notes
	//
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(16th))
	PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(16th))
	PlayTone(  933,    7); wait1Msec(  75);  // Note(D#, Duration(16th))
	PlayTone( 1481,    7); wait1Msec(  75);  // Note(B, Duration(16th))
	PlayTone(  831,    7); wait1Msec(  75);  // Note(C#, Duration(16th))
	PlayTone(  831,    7); wait1Msec(  75);  // Note(C#, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1320,    3); wait1Msec(  38);  // Note(A, Duration(32th))
	PlayTone(  831,    7); wait1Msec(  75);  // Note(C#, Duration(16th))
	PlayTone( 1481,    7); wait1Msec(  75);  // Note(B, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(16th))
	PlayTone( 1320,    3); wait1Msec(  38);  // Note(A, Duration(32th))
	PlayTone( 1320,    3); wait1Msec(  38);  // Note(A, Duration(32th))
	PlayTone(  831,    7); wait1Msec(  75);  // Note(C#, Duration(16th))
	PlayTone( 1481,    7); wait1Msec(  75);  // Note(B, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone( 1320,    7); wait1Msec(  75);  // Note(A, Duration(16th))
	PlayTone( 1175,    7); wait1Msec(  75);  // Note(G, Duration(16th))
	PlayTone(  988,    7); wait1Msec(  75);  // Note(E, Duration(16th))
	PlayTone(  933,    3); wait1Msec(  38);  // Note(D#, Duration(32th))
	PlayTone(  933,    3); wait1Msec(  38);  // Note(D#, Duration(32th))
	PlayTone( 1109,    3); wait1Msec(  38);  // Note(F#, Duration(32th))
	PlayTone(  933,    3); wait1Msec(  38);  // Note(D#, Duration(32th))
	PlayTone( 1481,    7); wait1Msec(  75);  // Note(B, Duration(16th))
	return;
}
int alpha=2950;
int gyroOffset,gyroRate,GyroRateOld=0,angVel,velocity=150;//100
int enc,encOld=0,encVel,errEnc,n=1;
float dT=5,u,uL,uL22,uL11,errL;//,uR;
float uk=1.1,angle=0,encVelSoft=0,uSoft=0,iEnc=0,path=0;
void Reset_1()
{
	sleep(100);resetGyro(S2);sleep(100);
}
void calibration_1()
{
	Reset_1();
	for(int i=0; i<10;i++)
	{
		gyroRate=getGyroRate(S2);
		if(gyroRate!=GyroRateOld) i=0;
		GyroRateOld=gyroRate;
		sleep(15);
		displayBigTextLine(1,"gyro rate=%d",gyroRate);//getGyroRate(S2)
	}
	playSound(soundDownwardTones);
	gyroOffset=gyroRate;
	displayBigTextLine(5,"gyroOffset=%d",gyroOffset);
	nMotorEncoder[motorB]=nMotorEncoder[motorC]=0;
}
task ac ()
{
	while(velocity<225)
	{
		velocity++;
		sleep(10);}

}
void turn()
{

	int oldVelocity =velocity;
	velocity=0;
	uL=15;
	sleep(4000);//t1=4000;
	velocity=oldVelocity;
	uL=0;
	sleep(4300);//t2=1500

	while(SensorValue[S3]>15)
	{
		uL11=20;//16
		uL22=14;//7
	}
	uL=0;
	sleep(1000);//t3=1000
	uL=15;
	oldVelocity =velocity;
	velocity=0;

	sleep(7550);//t4=2550
	velocity=oldVelocity;
}
task balancing()
{Reset_1();
	while(true)
	{
		gyroRate=getGyroRate(S2);
		if(abs(gyroRate)>500) gyroRate=0;
		angVel=getGyroRate(S2)-gyroOffset;
		angle=angle+angVel*dT*0.001;
		gyroOffset=gyroRate*0.002+gyroOffset*0.998;
		enc=(nMotorEncoder[motorB]+nMotorEncoder[motorC])/2;
		encVel=enc-encOld;
		encOld=enc;
		encVelSoft = encVelSoft * 0.9 + encVel * 0.1;
		iEnc=iEnc+errEnc*dT*0.001;
		path=path+velocity*0.001*dT;
		errEnc=enc-path;
		u=angVel *2.8 + angle * 45 + errEnc * 0.7 + encVelSoft * 50 + iEnc*0.8;//angVel*2.8////angle*33///
		uSoft=uSoft * 0.9 + u *0.1;

		motor[motorB]=uSoft*uk-uL+uL11;
		motor[motorC]=uSoft*uk+uL+uL22;

		sleep(dT);
		displayBigTextLine(7,"angVel=%d",angVel);
		displayBigTextLine(9,"angle=%d",angle);

	}
}
task Line()
{
	while(true)
	{
		if(SensorValue[S1]>15)//far
		{if(SensorValue[S1]<25) velocity=100;n=0;
			errL=SensorValue[S4]-SensorValue[S3];
			uL=errL*4.0;
			sleep(1);

		}
		else
		{//int oldVelocity2 =velocity;
			//velocity=100;

			startTask(xD);

			//if(SensorValue[S1]>15)
			turn();
			velocity=175;
			//	stopTask(ac);
			startTask(ac);
			n=1;


		}
	}
}

task main()
{
	calibration_1();
	startTask(balancing);//
	uL=0;
	sleep(3000);
	startTask(Line);
	//startTask(xD);
	//	velocity=0;
	startTask(ac);

	//	while(velocity>200)
	//	{
	//	velocity--;
	//	sleep(30);
	//		}


	//
	//
	while(true) sleep(1);


}
