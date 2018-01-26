import cv2
import numpy as np
img=cv2.imread('approx.jpg')
imgray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
ret,thresh = cv2.threshold(imgray,127,255,0)
# cv2.imshow('mask',thresh)
a,corners,b=cv2.findContours(thresh,1,2)
print(len(corners))
if len(corners)!=0:
    cnt=corners[0]

    cv2.drawContours(img,corners,-1,(0,255,0),2)
    hull = cv2.convexHull(cnt)
    print(cv2.arcLength(cnt,True))
    epsilon = 0.09  * cv2.arcLength(cnt, True)
    approx = cv2.approxPolyDP(cnt, epsilon, True)
    cv2.drawContours(img,[approx],-1,(200,0,0),5)
    cv2.imshow('img2',img)
    cv2.imshow('img',img)

    pass
cv2.waitKey()