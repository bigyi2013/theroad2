import cv2
import numpy as np
import time


class Params(object):
    def __init__(self):
        self.numPos = 0
        self.numNeg = 0
        self.numStages = 0
def oldhaar1(x, y, w, h, img):
    # haar1 定义为上下结构 ，上面是黑块，下面是白块
    a = ([y,x], [y,x+w], [int(y + h / 2),x], [ int(y + h / 2),x + w], [ y + h,x], [y + h,x+w])
    # 标准化检测框内图像
    sum = np.sum(img[a[0][0]:a[5][0], a[0][1]:a[5][1]])
    square = np.sum(np.square(img[a[0][0]:a[5][0], a[0][1]:a[5][1]]))
    mean = sum / (w * h)
    sqmean = square / (w * h)
    varnormfactor = np.sqrt(abs(mean * mean - sqmean))
    # 白块减黑块
    sum1 = np.sum(img[a[2][0]:a[5][0], a[2][1]:a[5][1]])
    sum2 = np.sum(img[a[0][0]:a[3][0], a[0][1]:a[3][1]])
    featurevalue = float(sum1) - float(sum2)
    print('square1:', square)
    normvalue = featurevalue / varnormfactor
    return normvalue

def haar1(x, y, w, h, jifen, jifen2, img):
    # haar1 定义为上下结构 ，上面是黑块，下面是白块
    a = (jifen[y,x], jifen[y,x+w], jifen[ int(y + h / 2),x], jifen[ int(y + h / 2),x + w,], jifen[ y + h,x],
         jifen[ y + h,x + w])
    b = (jifen2[y, x], jifen2[y, x + w], jifen2[int(y + h / 2),x], jifen2[int(y + h / 2), x + w,], jifen2[y + h, x],
         jifen2[y + h, x + w])
    # 标准化检测框内图像
    sum = a[5] - a[4] - a[1] + a[0]
    square = b[5] - b[4] - b[1] + b[0]
    mean = sum / (w * h)
    sqmean = square / (w * h)
    varnormfactor = np.sqrt(abs(mean * mean - sqmean))
    # 白块减黑块
    featurevalue = a[5] - a[4] - a[3] + a[2] - (a[3] - a[2] - a[1] + a[0])
    print('square2:',square)
    normvalue = featurevalue / varnormfactor
    return normvalue



def jifenimg(img):
    # img2不是图像格式，是arrary格式，值可以大于255
    jifen = np.zeros([img.shape[0]+1, img.shape[1]+1])
    jifen2 = np.zeros([img.shape[0]+1, img.shape[1]+1])
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            jifen[i+1, j+1] = int(np.sum(img[0:i + 1, 0:j + 1]))
            jifen2[i+1, j+1] = int(np.sum(np.square(img[0:i + 1, 0:j + 1])))
    return jifen, jifen2


def getvalues(dir, num):
    img = cv2.imread(dir, 0)
    img255 = np.zeros([img.shape[0], img.shape[1]])
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            img255[i, j] = img[i, j]
    print('img255:',img255)
    jifen, jifen2 = jifenimg(img255)
    imgsize = (5, 5)
    for x in range(0, imgsize[0]):
        for y in range(0, imgsize[1]):
            for w in range(2, imgsize[0] + 1):
                for h in range(2, imgsize[1] + 2, 2):
                    if (x + w) <= imgsize[0] and (y + h) <= imgsize[1]:
                        # haar定义参数：haar1(x,y,w,h,img)
                        value = oldhaar1(x, y, w, h, img255)
                        newvalue = haar1(x, y, w, h, jifen, jifen2, img255)
                        print('********************')

def main():
    num = 43200
    params = Params()
    params.numPos = 1
    params.numNeg = 1
    numpos = 1
    numneg = 1
    params.numStages = 20
    dir = '55.jpg'
    getvalues(dir, num)


if __name__ == '__main__':
    main()
