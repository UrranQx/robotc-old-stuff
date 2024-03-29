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
*/


int gyroOffset,gyroRate,GyroRateOld=0,angVel,velocity=400;//100
int enc,encOld=0,encVel,errEnc;
float dT=5,u,uL,errL,uL11,uL22;
float uk=1,angle=0,encVelSoft=0,uSoft=0,iEnc=0,path=0;
void Reset_1()
{
	sleep(1);resetGyro(S2);sleep(1);
}
void turn()
{

	int oldVelocity =velocity;
	velocity=0;
	uL=25;
	sleep(1000);//t1=4000;
	velocity=oldVelocity;
	uL=0;
	sleep(100);//t2=1500

	while(SensorValue[S3]>15)
	{
		uL11=20;//16
		uL22=5;//7
	}
	uL=0;
	sleep(1000);//t3=1000
	uL=25;
	oldVelocity =velocity;
	velocity=0;

	sleep(1050);//t4=2550
	velocity=oldVelocity;
}
void calibration_1()
{
	Reset_1();
	for(int i=0; i<10;i++)
	{
		gyroRate=getGyroRate(S2);
		if(gyroRate!=GyroRateOld) i=0;
		GyroRateOld=gyroRate;
		sleep(10);
		displayBigTextLine(1,"gyro rate=%d",gyroRate);//getGyroRate(S2)
	}
	playSound(soundDownwardTones);
	gyroOffset=gyroRate;
	displayBigTextLine(5,"gyroOffset=%d",gyroOffset);
	nMotorEncoder[motorB]=nMotorEncoder[motorC]=0;
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
		u=angVel *1.5 + angle *13+ errEnc * 0.1 + encVelSoft *50 + iEnc*0.1;//angVel*2.8////angle*33///
		uSoft=uSoft * 0.9 + u *0.1;

		motor[motorB]=uSoft*uk-1.2*uL+uL11;
		motor[motorC]=uSoft*uk+1.2*uL+uL22;

		sleep(dT);
		displayBigTextLine(7,"angVel=%d",angVel);
		displayBigTextLine(9,"angle=%d",angle);

	}
}
task Line()
{float es,eold,e,k1=4.1,k2=4.5;
	es = SensorValue[S4]-SensorValue[S3];
	eold = 0;


	while(true)
	{
		if (SensorValue[S1]>15)
		{
			e = SensorValue[S4]-SensorValue[S3]-es;
			uL = k1*e+k2*(e-eold);
			eold = e;
			//	errL=SensorValue[S4]-SensorValue[S3];
			//uL=errL*3.0;
			sleep(1);
		}
		else
		{
		//	turn();
			//velocity=300;
		}
	}
}
task main()
{
	calibration_1();
	startTask(balancing);
	startTask(Line);
	//startTask(xD);
	//velocity=0;

//	while(velocity<250)
	//{
	//	velocity++;
//	sleep(1);
//	}

	//	while(velocity>200)
	//{
	//		velocity--;
	//		sleep(10);
	//}

	while(true) sleep(1);


}
