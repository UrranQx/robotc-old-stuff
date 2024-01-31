
task main()
{
wait1Msec(500);
float gyroOffset = 0;
int gyroRate, gyroRateOld=0;
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

}
