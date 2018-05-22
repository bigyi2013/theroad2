import cv2
import numpy as np
import time
import threading
import math


# flag=0 ,定义为大于阈值为正

class Params(object):
    def __init__(self):
        self.numPos = 1000
        self.numNeg =1000
        self.numStages = 0
        self.imgsize = (24, 24)
        self.haar1num = 33396
        self.M = 20

def main():
    #计算正样本和负样本的hog特征值，然后储存在txt中。
    params = Params()
    values = np.zeros((params.numNeg + params.numPos, params.haar1num))
    for i in range(params.numPos):
        dir = './face/' + str(i) + '.jpg'
        print('得到正样本' + str(i) + '图片的value')
    for i in range(params.numNeg):
        dir = './nface/' + str(i) + '.jpg'
        print('得到负样本' + str(i) + '图片的value')
if __name__ == '__main__':
    main()
