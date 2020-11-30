I = imread("eight.tif");
figure,imshow(I);
J = imnoise(I,"salt & pepper",0.02);
h=fspecial('average',2);
filter_image=imfilter(J,h);
imshow(filter_image);
