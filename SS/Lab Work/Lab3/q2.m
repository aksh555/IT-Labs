clc;
clear all;
close all;
x  = [2 1 2 1];
h = [1 2 3];
lim_lin = length(x)+length(h)-1;
lim_circ = max(length(x),length(h));

n= 0:lim_lin;
y = conv(x,h); 
yl=[y 0];
stem(n,yl);
figure(2);
title("Linear");
xlabel('n');
ylabel('LinConv');

n= 0:lim_circ;
y1 = y(1:lim_circ);
y2 = [y(lim_circ+1:end) zeros(1,2*lim_circ-lim_lin)];
yc  = y1+ y2;
yc=[yc 0];
stem(n,yc);
figure(1);
title("Circular");
xlabel('n');
ylabel('CircConv');
