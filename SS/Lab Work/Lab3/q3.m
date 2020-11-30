clc;
clear all;
close all;
n = input("Enter value of t");
t=-2*n:1:2*n;
t1=-n:1:0;
t2=1:1:n;
t3 =-n:1:-1;
t4 = 0:1:n;

h1 = [zeros(1,length(t3))];
h2= ones(1,length(t4)).*exp(-t4);
h = [h1 h2];
x = ones(1,length(t2));
x = [zeros(1,length(t1)) x];
y = conv(x,h);
plot(t,y);

