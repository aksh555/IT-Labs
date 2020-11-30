T = 10*(1/50);

fs = 1000;
t = 0:1/fs:T-1/fs;

x = sawtooth(2*pi*50*t,1/2);
y = fft(x);
figure;
subplot(2,1,1); plot(t,x);
grid on
subplot(2,1,2); 
f = (0:length(y)-1)*50/length(y);
plot(f,abs(y))