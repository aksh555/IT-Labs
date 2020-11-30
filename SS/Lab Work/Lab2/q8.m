I = imread("rice.png");
J = imread("cameraman.tif");
K = imadd(I,J,"uint16");

figure,imshow(I);
figure,imshow(J);
figure,imshow(K,[]);
