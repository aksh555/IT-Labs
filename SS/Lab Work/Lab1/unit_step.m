clc; close all; clear all;
n=input("Enter a value");
t=0:1:n-1;
y=ones(1,n);
figure(2);
stem(t,y);
title("Unit Step");
