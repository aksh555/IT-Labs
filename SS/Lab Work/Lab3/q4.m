clc;
clear all;
close all;
l = input("Enter value of n ");
n = -2*l:1:2*l;
n1 = -l:1:1;
n2 = 2:1:l;
h = [zeros(1,length(-l:1:-3)) ones(1,length(-2:1:l))];
x = [zeros(1,length(n1)) ones(1,length(n2)).*power(0.5,n2-2)];

y = conv(x,h);
stem(n,y);