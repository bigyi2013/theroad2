import cv2
import numpy as np
img1=cv2.imread('red.jpg',0)
img=cv2.imread('red.jpg',0)
print('1')
laplacian=cv2.Laplacian(img,cv2.CV_64F)
print('2')
cv2.imshow('laplacian',laplacian)
cv2.waitKey()