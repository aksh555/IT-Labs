myvoice=audiorecorder;
disp("start speaking");
recordblocking(myvoice,5);
disp("end of recording..playing back");
play(myvoice);