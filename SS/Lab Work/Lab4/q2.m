% Fourier Series Expansion for Square Wave
%% Parameters as mentioned in text
% http://www.eas.uccs.edu/~mwickert/ece2610/lecture_notes/ece2610_chap3.pdf
f = 500; % Frequecny 
C = 4/pi; % Constant Value
dt = 5.0e-05; % Interval between teo time steps
tpts = (4.0e-3/5.0e-5) + 1; % Total points &quot;(final point-initial point)/Interval+1%
for n = 1: 12 % Values we are considering to approximate Fourier Seires instead of infinity as given in original function x(t)
for m = 1: tpts % Here, we'll consider all &quot;t&quot; points to cover &quot;from 0 to 4ms interval&quot;
s1(n,m) = (4/pi)*(1/(2*n - 1))*sin((2*n - 1)*2*pi*f*dt*(m-1)); % Approximate Fourier Series g(t)
end
end
for m = 1:tpts
a1 = s1(:,m); % VERY IMPORTANT ! Here, we are assigning a1 for each single column (total 81)
a2(m) = sum(a1); % Here, we are summing up the whole column to one single value (adding all 12 values in one column) 
end
% Now, we have a row vector &quot;a2&quot; with total values &quot;81&quot;
f1 = a2'; % Here, we have final values &quot;f1&quot; (total 81 points) as transpose of a2 computed above
t = 0.0:5.0e-5:4.0e-3; % it's already given in text (0 to 4ms with interval of 0.05 ms)
%% Plotting results
%plot(t,f1,'g',f1,abs(f1),'b',f1,angle(f1),'r')
subplot(3,1,1);
plot(t,f1)
title('Fourier Series Expansion')
 hold on;
subplot(3,1,2);
plot(f1,abs(f1));
title('Amplitude spectrum')
 hold on;
 subplot(3,1,3);
 plot(f1,angle(f1));
 title('Phase spectrum')
 hold off;
xlabel('Time, s')
ylabel('Amplitude, V')
