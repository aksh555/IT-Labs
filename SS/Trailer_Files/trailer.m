
image_names = {'i5.jpg','i5.jpg','i5.jpg','i5.jpg','i5.jpg','i9.jpg','i9.jpg','i9.jpg','i11.jpg','i11.jpg','i11.jpg','i10.jpg','i10.jpg','i10.jpg','i12.jpg','i12.jpg','i12.jpg','i1.jpg','i1.jpg','i1.jpg','i14.jpg','i14.jpg','i14.jpg','i14.jpg','i14.jpg','i14.jpg','i13.jpg','i13.jpg','i3.jpg','i3.jpg','i15.jpg','i15.jpg','i6.jpg','i6.jpg','i6.jpg','i7.jpg','i7.jpg','i7.jpg'};
 movie_obj = VideoWriter('Trailer.avi');
movie_obj.FrameRate = 1;
open(movie_obj);

for K = 1 : length(image_names)
  this_image = imread(image_names{K});
  writeVideo(movie_obj, this_image);
end
close(movie_obj);

[y, Fs] = audioread('au4.mp3');
player = audioplayer(y, Fs);
play(player);