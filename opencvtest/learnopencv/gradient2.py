import cv2
import numpy as np
img=cv2.imread('red.jpg',0)
cv2.imshow('img',img)
laplacian=cv2.Laplacian(img,cv2.CV_64F)
sobelx = cv2.Sobel(img,cv2.CV_8U,1,0,ksize=5)
sobely = cv2.Sobel(img,cv2.CV_8U,0,1,ksize=5)
cv2.imshow('laplacian',laplacian)
cv2.imshow('x',sobelx)
cv2.imshow('y',sobely)
cv2.waitKey()