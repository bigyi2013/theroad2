import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt
img = cv.imread('aa.jpg',0)
clahe = cv.createCLAHE(clipLimit=2.0, tileGridSize=(15,15))
img2 = clahe.apply(img)

bimg= cv.bilateralFilter(img,9,75,75)
bimg2= cv.bilateralFilter(img2,9,75,75)
# bimg = cv.medianBlur(img,5)
# bimg2 = cv.medianBlur(img2,5)
# bimg2 = cv.GaussianBlur(img2,(5,5),0)
# ret,th1 = cv.threshold(img,127,255,cv.THRESH_BINARY)
# th2 = cv.adaptiveThreshold(img,255,cv.ADAPTIVE_THRESH_MEAN_C,\
#             cv.THRESH_BINARY,11,2)
th = cv.adaptiveThreshold(bimg,255,cv.ADAPTIVE_THRESH_GAUSSIAN_C,\
            cv.THRESH_BINARY,11,2)
th2 = cv.adaptiveThreshold(bimg2,255,cv.ADAPTIVE_THRESH_MEAN_C,\
            cv.THRESH_BINARY,11,2)
edges=cv.Laplacian(bimg2,10)
edges2=cv.Laplacian(th2,10)

plt.subplot(2,2,1),plt.imshow(img,'gray')
plt.title('img')
plt.subplot(2,2,2),plt.imshow(edges,'gray')
plt.title('edges')
plt.subplot(2,2,3),plt.imshow(th,'gray')
plt.title('th2')
plt.subplot(2,2,4),plt.imshow(th2,'gray')
plt.title('th3')
plt.xticks([]),plt.yticks([])
plt.show()