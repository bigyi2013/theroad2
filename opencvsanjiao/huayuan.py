import numpy as np
import cv2
import random
img=cv2.imread("1.jpg")
qidianx=2383
qidiany=2366
length=725
cor = 100
width=20
cv2.circle(img,(qidianx,qidiany),length,100,20)
cv2.imwrite("new.jpg",img)


