import cv2
import numpy as np
from matplotlib import  pyplot as plt

img=cv2.imread('hist1.jpg')
hist,bins = np.histogram(img.ravel(),256,[0,256])
cdf = hist.cumsum()
cdf_normalized = cdf * hist.max()/ cdf.max()
plt.plot(cdf_normalized, color = 'b')
plt.hist(img.flatten(),256,[0,256],color='g')
plt.xlim([0,256])
cv2.imshow('img',img)
plt.legend(('cdf','histogram'), loc = 'upper left')
plt.show()
