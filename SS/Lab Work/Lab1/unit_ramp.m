clc; clear all; close all;
n=input("Enter n value");
t=0:n;
y=ones(1,n);
figure(3);
stem(t,t);
title("Unit Ramp");
