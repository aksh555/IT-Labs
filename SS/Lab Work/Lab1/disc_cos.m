clc; clear all; close all;
t=0:.01:pi;
y=cos(2*pi*t);
stem(t,y);
ylabel("Amp"); xlabel("(a)n..");
title("Cosine Signal");