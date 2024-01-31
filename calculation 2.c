
task main()

{

  float a=5,b=4,c=1;
	//int a=5,b=4;
	displayBigTextLine(0,"a=%d b=%d",a, b);
	displayBigTextLine(4,"%d+%d=%d",a,b,a+b);
	displayBigTextLine(8,"%d-%d=%d",a,b,a-b);
	displayBigTextLine(10,"%f/%f=%4.2f",a,b,a/b);
	for(int i=1;i<=b;i++)
		c=c*a;
   displayTextLine(6,"%d^%d=%d",a,b,c);
	wait1Msec(100000);






}
