clc;
clear all;
close all;
x  = [1 -1 -1 -1 1 0 1];
h = [5 -4 3 2 -1 1 0 -1];
lim_lin = length(x)+length(h)-1;
lim_circ = max(length(x),length(h));
n= 0:lim_circ;
y = conv(x,h); 
y1 = y(1:lim_circ);
y2 = [y(lim_circ+1:end) zeros(1,2*lim_circ-lim_lin)];
y  = y1+ y2;
y=[y 0];
stem(n,y);
xlabel('n');
ylabel('CircConv');

