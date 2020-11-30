clc; clear all; close all;
t=0:.01:6.28;
y1=sin(t);
y2=sin(2*t);
y3=sin(5*t);
figure(1);
plot(t,y1,'o',t,y2,'--',t,y3);
ylabel("Amp"); xlabel("(a)n..");
title("Sine Signals");
