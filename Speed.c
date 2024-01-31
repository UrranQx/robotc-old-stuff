
task main()
{
 for (int i=0;i<100;i=i+10)
 {motor[motorB]=i;
   motor[motorC]=i;
   wait1Msec(100);
 }
 wait1Msec(1000);
 for (int i=100;i>0;i=i-2)
 {motor[motorB]=i;
   motor[motorC]=i;
   wait1Msec(100);
 }



}
