import cv2
import numpy as np
from matplotlib  import pyplot as plt
img=cv2.imread('hist1.jpg',0)
img2=cv2.imread('hist1.jpg',0)
equ=cv2.equalizeHist(img)
clahe = cv2.createCLAHE(clipLimit=2.0, tileGridSize=(8,8))
cl1 = clahe.apply(img)
plt.subplot(231),plt.imshow(img2,'gray')
plt.subplot(232),plt.imshow(equ,'gray')
plt.subplot(233),plt.imshow(cl1,'gray')
plt.subplot(234),plt.hist(img.flatten(),256,[0,256], color = 'g')
plt.subplot(235),plt.hist(equ.flatten(),256,[0,256], color = 'g')
plt.subplot(236),plt.hist(cl1.flatten(),256,[0,256], color = 'g')
plt.show()
cv2.waitKey()