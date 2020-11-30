clc;
clear all;
close all;
x1=[7 5 4 0];
x2=[0 3 6 2 9];
L=length(x1);
M=length(x2);
N=L+M-1;
y=conv(x1,x2);
disp("The value of y: ");
disp(y);

n1=0:L-1;
subplot(311);
stem(n1,x1);
grid on;
xlabel("n1");
ylabel("amplitude");
title("first seq");


n2=0:M-1;
subplot(312);
stem(n2,x2);
grid on;
xlabel("n2");
ylabel("amplitude");
title("second seq");

n3=0:N-1;
subplot(313);
stem(n3,y);
grid on;
xlabel("n3");
ylabel("amplitude");
title("convoluted op");
