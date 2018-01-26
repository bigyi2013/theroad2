load('C:\Users\yehoo\Desktop\calibrationSession2.mat')
Camera=calibrationSession.CameraParameters;
Trans=Camera.TranslationVectors;
Rots=Camera.RotationMatrices;
[mt,nt]=size(Trans);
for i=1:mt
a=Trans(i,:);
b=Rots(:,:,i);
pos=(-a)*(b^-1);
poslist(i,:)=pos; 
end