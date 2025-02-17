clc; clear all; close all;
t=0:.01:pi;
y1=sin(pi*t);
figure(1);
plot(t,y1);
ylabel("Amp"); xlabel("(a)n..");
title("Cont Sine Signal");
figure(2);
stem(t,y1);
ylabel("Amp"); xlabel("(a)n..");
title("Disc Sine Signal");
y2=cos(2*pi*t);
figure(3);
plot(t,y2);
ylabel("Amp"); xlabel("(a)n..");
title("Cont Cosine Signal");
figure(4);
stem(t,y2);
ylabel("Amp"); xlabel("(a)n..");
title("Disc Cosine Signal");
y3=cos(5*t + sin(2*t));
figure(5);
plot(t,y3);
ylabel("Amp"); xlabel("(a)n..");
title("Cont Signal");
figure(6);
stem(t,y3);
ylabel("Amp"); xlabel("(a)n..");
title("Disc Signal");