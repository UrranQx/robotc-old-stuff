task main(){float u,v,es,eold,e,k1=4,k2=3;es = SensorValue[S1]-SensorValue[S2];eold = 0;while(true){e = SensorValue[S1]-SensorValue[S2]-es;u = k1*e+k2*(e-eold);eold = e;v = -30-abs(u)*0.2;motor[motorB] = v+u;motor[motorC] = v-u;wait1Msec(1);	}}
