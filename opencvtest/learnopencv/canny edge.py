import cv2
import numpy as np
img=cv2.imread('red.jpg')
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
lower_blue = np.array([100,50,50])
upper_blue = np.array([130,255,255])
mask = cv2.inRange(hsv, lower_blue, upper_blue)
img1=cv2.Canny(mask,50,200)
cv2.imshow('img',img)
cv2.imshow('img1',img1)
cv2.imshow('mask',mask)
cv2.waitKey()
