fs=10000;
obj=audiorecorder(fs,8,1);
recordblocking(obj,8);
y=getaudiodata(obj);
sound(y,fs);