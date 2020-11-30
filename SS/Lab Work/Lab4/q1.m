 clear , close all;
 Fs=60;
 t=0:1/Fs:20-1/Fs;
 y=square(t,50);
 y(y>0)=2;
 y(y<0)=-12;
 figure, plot(t,y);
 axis ([0 20 -20 10])