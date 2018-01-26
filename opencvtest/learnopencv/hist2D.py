import cv2
import numpy as np
from matplotlib import pyplot as plt

img = cv2.imread('hist5.jpg')
histimg = cv2.calcHist([img],[1] , None, [256], [0, 256])
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
hist = cv2.calcHist([hsv], [0,2], None, [180, 256], [0, 180, 0, 256])
plt.imshow(hist)
cv2.imshow('img',img)
plt.show()
