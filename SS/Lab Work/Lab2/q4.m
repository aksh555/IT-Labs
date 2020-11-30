[y,fs]=audioread("/home/student/18IT132/SignalsLab/Lab2/anykey.wav");
t=1/fs:1/fs:length(y)/fs;
plot(t,y);