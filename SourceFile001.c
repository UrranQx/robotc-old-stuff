
task main()
{
	while (true){
int v=-10,k1=2,k=2,k3=1,k4=1,es1,es1old,u1;
if(SensorValue[S2]<15)
	{
 es1=SensorValue[S2]-9;
      u1=k3*es1+k4*(es1-es1old);
      es1=es1old;


		motor[motorB]=v+u1;
		motor[motorC]=v-u1;}
}}
