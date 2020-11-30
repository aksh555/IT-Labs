t = linspace(-2,2,10000);   % time
f = 0*t;                    % creates a zero valued function
 
N=7;                        % number of harmonics
for k=-N:1:N
 
    if(k==0)                % skip the zeroth term
        continue;
    end;
 
    C_k = ((1)/(pi*1i*k))*(1-exp(-pi*1i*k));    % computes the k-th Fourier coefficient of the exponential form
    f_k = C_k*exp(2*pi*1i*k*t);                 % k-th term of the series
    f = f + f_k;                                % adds the k-th term to f
 
end
 
plot(t, f, 'LineWidth', 2);
grid on;
xlabel('t');
ylabel('f(t)');
title(strcat('Fourier synthesis of the square wave function with n=', int2str(N), ' harmonics.' ));