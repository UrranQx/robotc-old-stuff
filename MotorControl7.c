int a_left=90,a_center=0,a_right=-90,b_up=-45,b_down=-1,c_open=-64,c_close=0,alpha=0,beta=0,gamma=0,maxi=10;
task motor1()
{float i=0,e,p,d,u,k=0.5,ki=0.001,kp=0.1,kd=1,eold=0;
	while (true)
	{	e=alpha-nMotorEncoder[motorA];
		i=i+ki*e;
		if(abs(i)>maxi) i=sgn(i)*maxi;
		p=k*e;
		d=kd*(e-eold);
		eold=e;
		u=p+i+d;
		motor[motorA]=u;
		wait1Msec(1);
	}
}
task motor2()
{float i2=0,e2,p2,d2,u2,k2=0.1,ki2=0.0001,kp2=0.01,kd2=1,eold2=0;
	while (true)
	{	e2=beta-nMotorEncoder[motorB];
		i2=i2+ki2*e2;
		if(abs(i2)>maxi) i2=sgn(i2)*maxi;
		p2=k2*e2;
		d2=kd2*(e2-eold2);
		eold2=e2;
		u2=p2+i2+d2;
		motor[motorB]=u2;
		wait1Msec(1);
	}
}
task motor3()
{float i3=0,e3,p3,d3,u3,k3=0.5,ki3=0.001,kp3=0.1,kd3=1,eold3=0;
	while (true)
	{	e3=gamma-nMotorEncoder[motorC];
		i3=i3+ki3*e3;
		if(abs(i3)>maxi) i3=sgn(i3)*maxi;
		p3=k3*e3;
		d3=kd3*(e3-eold3);
		eold3=e3;
		u3=p3+i3+d3;
		motor[motorC]=u3;
		wait1Msec(1);
	}
}
void left()
{gamma=c_open;sleep(1000);
	beta=b_up;sleep(1000);
	alpha=a_left;sleep(1000);
	beta=b_down;sleep(1000);
	gamma=c_close;sleep(1000);
	beta=b_up;sleep(1000);
	alpha=a_center;sleep(1000);
	beta=b_down;sleep(1000);
	gamma=c_open;sleep(1000);
	gamma=c_close;sleep(1000);
}
task main()
{nMotorEncoder[motorA]=0;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
		startTask(motor2);

	beta=b_up;sleep(3000);
beta=b_down;sleep(3000);


}
