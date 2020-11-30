clearvars;
close all;
t=1:1:50;

x=zeros(size(t));
x=(1-2*t).*exp(-2*t).*(t>=0);

y=fft(x);
f = (0:length(y)-1)*50/length(y);
subplot(2,1,1); plot(f,abs(y)); grid on;
subplot(2,1,2); plot(f,phase(y));