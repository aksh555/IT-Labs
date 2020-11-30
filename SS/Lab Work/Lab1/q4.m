clc; clear all; close all;
n=-30:0.1:30;
y1=sin(0.6*pi*n + 0.6*pi);
y2=2*cos(1.1*pi*n -0.5*pi);
y3=mod(n,6);
plot(n,y1,"o",n,y2,"--",n,y3);
