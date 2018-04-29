import cv2
import numpy as np
import  os
def jifen(img):
    #img2不是图像格式，是arrary格式，值可以大于255
    img2=np.zeros([img.shape[0],img.shape[1]])
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            img2[i,j]=int(np.sum(img[0:i+1,0:j+1]))
    return img2
def haar(jifen,type):
    pass
fileDir='./face2/'
for root, dirs, files in os.walk(fileDir):
    # print(root)
    # print(dirs)
    # print(files)
    for i in files:
        dir=fileDir+i
        img=cv2.imread(dir,0)
        cv2.imshow('img', img)
        img2=jifen(img)
        #得到积分后的图像，注意图像的值只能是0-255，ndarrary的值没有限制
        cv2.waitKey()