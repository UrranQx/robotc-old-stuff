
task main()
{int ko=0.0005;
wait1Msec(500);
float gyroOffset = 0;
int gyroRate, gyroRateOld=0;
float offset;
 float angVel;
for( int i=0;i<20;i++)
{
gyroRate= getGyroRate(S2);
if(gyroRate != gyroRateOld) i=0;
gyroRateOld= gyroRate;
wait1Msec(15);
displayBigTextLine(1,"rate%f",gyroRate);

}
gyroOffset=gyroRate;
displayBigTextLine(5,"offset%f",gyroOffset);
wait1Msec(100000);
offset=offset*ko+gyroRate*(1-ko);
 angVel=gyroRate-offset;
 float k3=0.7,encVel,k4=0.05;
 int enc,encOld=0,u;
 enc=(nMotorEncoder[motorB]+nMotorEncoder[motorC])/2;
 encVel=(enc-encOld)/(0.001*Td);
 encOld=encoder;
 u=andVel*k1+angle*k2-enc*k3+encVel*k4;

}
