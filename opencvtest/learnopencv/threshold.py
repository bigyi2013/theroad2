import cv2
import numpy as np
from matplotlib import pyplot as plt
img=cv2.imread('grad.jpg')
cv2.imshow('img',img)
ret,thresh1=cv2.threshold(img,127,255,cv2.THRESH_BINARY)
cv2.imshow('thresh_binary',thresh1)
cv2.waitKey()