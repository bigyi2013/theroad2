import cv2
import numpy as np
import time
import math


class Params(object):
    def __init__(self):
        self.numPos = 200
        self.numNeg = 200
        self.numStages = 0
        self.imgsize = (64, 128)
        self.haar1num = 33396
        self.M = 20
        self.blocksize = 16
        self.blockstep = 8
        self.cellsize = 8

    def woyebuzhidaoqishenmemingzi(self, pcell):
        # 通过判断atan的大小，来建立9个方向的梯度直方图。
        p = 180 * pcell / math.pi
        if -90 <= p < -80:
            return 1
        elif -80 <= p < -60:
            return 2
        elif -60 <= p < -40:
            return 3
        elif -40 <= p < -20:
            return 4
        elif -20 <= p < 0:
            return 5
        elif 0 <= p < 20:
            return 6
        elif 20 <= p < 40:
            return 7
        elif 40 <= p < 60:
            return 8
        elif 60 <= p < 80:
            return 9
        elif 80 <= p <= 90:
            return 1
        elif math.isnan(p):
            return 1
        else:
            return 0

    def cellvalue(self, m, n):
        size = self.cellsize
        wcell = self.img1[m:m + size, n:n + size]
        pcell = self.img2[m:m + size, n:n + size]
        pin9 = np.zeros((1, 9))
        if wcell.size != 0:
            wcell64 = wcell.reshape(1, size * size)
            pcell64 = pcell.reshape(1, size * size)
            for i in range(0, 64):
                pin = self.woyebuzhidaoqishenmemingzi(pcell64[0, i])
                if pin == 0:
                    print('程序出错了，这个pin怎么能为0呢？ ')
                    pass
                else:
                    pin9[0, pin - 1] += wcell64[0, i]
        else:
            pass
        return pin9
        # return value

    def blockvalue(self, m, n):
        values = np.ones((1, 9))
        for i in range(0, self.blocksize, self.cellsize):
            for j in range(0, self.blocksize, self.cellsize):
                value = self.cellvalue(m + i, n + j)
                values = np.append(values, value, axis=0)
        values = np.delete(values, 0, axis=0)
        return values

    def gamma(self, img):
        img2 = np.sqrt(img)
        return img2

    def gethog(self):
        valueslist = np.zeros((1, 9))
        for i in range(0, self.m - self.blockstep, self.blockstep):
            for j in range(0, self.n - self.blockstep, self.blockstep):
                values = self.blockvalue(i, j)
                valueslist = np.append(valueslist, values, axis=0)
        valueslist = np.delete(valueslist, 0, axis=0)
        return valueslist

    def tidu(self, img):
        self.img1 = np.zeros(img.shape)
        self.img2 = np.zeros(img.shape)
        for i in range(img.shape[0]):
            for j in range(img.shape[1]):
                if 1 < j < img.shape[1] - 1 and 1 < i < img.shape[0] - 1:
                    y = img[i + 1, j] - img[i - 1, j]
                    x = img[i, j + 1] - img[i, j - 1]
                    self.img1[i, j] = math.sqrt(x * x + y * y)
                    self.img2[i, j] = math.atan(y / x)
                else:
                    # 边缘区域，不处理
                    pass

    def initimg(self, dir):
        img = cv2.imread(dir, 0)
        imgnp = np.array(img, dtype=float)
        self.m, self.n = img.shape
        self.imgnp = imgnp
        img2 = self.gamma(imgnp)
        self.tidu(img2)


def IOresult(a, result):
    result = result.reshape(1, 3780)
    with open('./test1.txt', 'a') as f:
        if a == 1:
                f.write('1 ')
        else:
                f.write('0 ')
        for i in result[0]:
                f.write(str(i) + str(' '))
        f.write(str('\n'))


def main():
    params = Params()
    s=200
    for i in range(params.numPos):
        dir = './face64/' + str(s+i) + '.jpg'
        print('得到正样本' + str(i) + '图片的value')
        params.initimg(dir)
        valueslist = params.gethog()
        # valueslist 是一个420*9 的矩阵，共有3780个特征点。
        # 保存在result.txt 文件中。
        IOresult(1, valueslist)

    for i in range(params.numNeg):
        dir = './nface64/' + str(s+i) + '.jpg'
        print('得到负样本' + str(i) + '图片的value')
        params.initimg(dir)
        valueslist = params.gethog()
        # valueslist 是一个420*9 的矩阵，共有3780个特征点。
        # 保存在result.txt 文件中。
        IOresult(0, valueslist)


if __name__ == '__main__':
    main()
