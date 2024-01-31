int a_left=90,a_center=0,a_right=-90,b_up=-35,b_down=-3,c_open=64,c_close=0,alpha=0,beta=0,gamma=0,maxi=10;
task motors()
{float i=0,e,p,d,u,k=0.5,ki=0.001,kp=0.1,kd=1,eold=0,
	i2=0,e2,p2,d2,u2,k2=0.5,ki2=0.001,kp2=0.1,kd2=1,eold2=0,
	i3=0,e3,p3,d3,u3,k3=1,ki3=0.001,kp3=0.1,kd3=1,eold3=0;
	while (true)
	{	e=alpha-nMotorEncoder[motorA];e2=beta-nMotorEncoder[motorB];e3=gamma-nMotorEncoder[motorC];
		i=i+ki*e;	i2=i2+ki2*e2; i3=i3+ki3*e3;
		if(abs(i)>maxi) i=sgn(i)*maxi;	if(abs(i2)>maxi) i2=sgn(i2)*maxi;	if(abs(i3)>maxi) i3=sgn(i3)*maxi;
		p=k*e;	p2=k2*e2; 	p3=k3*e3;
		d=kd*(e-eold); d2=kd2*(e2-eold2);	d3=kd3*(e3-eold3);
		eold=e; eold2=e2; eold3=e3;
		u=p+i+d;	u2=p2+i2+d2; u3=p3+i3+d3;
		motor[motorA]=u; motor[motorB]=u2;	motor[motorC]=u3;
		wait1Msec(1);
	}
}

void left()
{gamma=c_open;sleep(3000);
	beta=b_up;sleep(3000);
	alpha=a_left;sleep(3000);
	beta=b_down;sleep(3000);
	gamma=c_close;sleep(3000);
	beta=b_up;sleep(3000);
	alpha=a_center;sleep(3000);
	beta=b_down;sleep(3000);
	gamma=c_open;sleep(3000);
	gamma=c_close;sleep(3000);
}
void custom()
{int sl=2500;
gamma=c_open;sleep(sl);
beta=-80;sleep(sl);
alpha=180;sleep(sl);
alpha=90;sleep(sl);
beta=0;sleep(sl);
gamma=c_close;sleep(sl);
beta=-20;sleep(sl);
alpha=-90;sleep(sl);
beta=0;sleep(sl);
gamma=c_open;sleep(sl);
beta=b_up;sleep(sl);
alpha=a_center;sleep(sl);
gamma=c_close;sleep(sl);
beta=b_down;sleep(sl);

}
task main()
{nMotorEncoder[motorA]=0;
	nMotorEncoder[motorB]=0;
	nMotorEncoder[motorC]=0;
	startTask(motors);


left();
custom();


}
