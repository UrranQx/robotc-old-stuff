task screen()
{
	while(true)
	{
		int Screen1=SensorValue[S1];
		displayBigTextLine(2,"Do stenkie=%d",Screen1);
		sleep(10);
	}
}
