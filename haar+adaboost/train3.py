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


def haar1(x, y, w, h, jifen, jifen2, img):
    # haar1 定义为上下结构 ，上面是黑块，下面是白块
    a = (jifen[y, x], jifen[y, x + w], jifen[int(y + h / 2), x], jifen[int(y + h / 2), x + w,], jifen[y + h, x],
         jifen[y + h, x + w])
    b = (jifen2[y, x], jifen2[y, x + w], jifen2[int(y + h / 2), x], jifen2[int(y + h / 2), x + w,], jifen2[y + h, x],
         jifen2[y + h, x + w])
    # 标准化检测框内图像
    sum = a[5] - a[4] - a[1] + a[0]
    square = b[5] - b[4] - b[1] + b[0]
    mean = sum / (w * h)
    sqmean = square / (w * h)
    varnormfactor = np.sqrt(abs(mean * mean - sqmean))
    # 白块减黑块
    featurevalue = a[5] - a[4] - a[3] + a[2] - (a[3] - a[2] - a[1] + a[0])
    normvalue = featurevalue / varnormfactor
    return normvalue


def jifenimg(img):
    # img2不是图像格式，是arrary格式，值可以大于255
    jifen = np.zeros([img.shape[0] + 1, img.shape[1] + 1])
    jifen2 = np.zeros([img.shape[0] + 1, img.shape[1] + 1])
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            jifen[i + 1, j + 1] = int(np.sum(img[0:i + 1, 0:j + 1]))
            jifen2[i + 1, j + 1] = int(np.sum(np.square(img[0:i + 1, 0:j + 1])))
    return jifen, jifen2


def GetValueHaar1(dir):
    params = Params()
    num = params.haar1num
    imgsize = params.imgsize
    valuelist = np.array([])
    img = cv2.imread(dir, 0)
    img255 = np.zeros([img.shape[0], img.shape[1]])
    for i in range(img.shape[0]):
        for j in range(img.shape[1]):
            img255[i, j] = img[i, j]
    jifen, jifen2 = jifenimg(img255)
    for x in range(0, imgsize[0] + 1):
        for y in range(0, imgsize[1] + 1):
            for w in range(2, imgsize[0] + 1):
                for h in range(2, imgsize[1] + 2, 2):
                    if (x + w) < imgsize[0] and (y + h) < imgsize[1]:
                        # haar定义参数：haar1(x,y,w,h,img)
                        # value = oldhaar1(x, y, w, h, img255)
                        newvalue = haar1(x, y, w, h, jifen, jifen2, img255)
                        valuelist = np.append(valuelist, newvalue)
    valuelist = np.reshape(valuelist, (1, num))
    return valuelist


def getyi(value, flag, thre):
    params=Params()
    lables = np.append(np.ones((1, params.numPos), dtype=np.int),
                       np.zeros((1, params.numNeg), dtype=np.int))
    if flag == 0:
        newvalue = np.array([value > thre])
    else:
        newvalue = np.array([value <= thre])
    ones = np.ones((1, newvalue.shape[1]), dtype=np.int)
    yi = ones * np.logical_xor(lables, newvalue)
    # yi 与 fx不相等,也就是分类错误时，yi置1.
    return yi


def rfen(value, wi):
    # minem=np.ones((1,4))
    # flag=0 ,定义为大于阈值为正
    flag = 0
    ems = np.ones((1, 3))
    params = Params()
    sort = np.sort(value)
    for j in range(len(sort) + 1):
        if j == 0:
            thre = sort[j] - 0.01
        elif j == len(sort):
            thre = sort[j - 1]
        else:
            thre = (sort[j] + sort[j - 1]) / 2
        lables = np.append(np.ones((1, params.numPos), dtype=np.int),
                           np.zeros((1, params.numNeg), dtype=np.int))
        # 大于阈值为正
        newvalue = np.array([value > thre])
        ones = np.ones((1, newvalue.shape[1]), dtype=np.int)
        yi = ones * np.logical_xor(lables, newvalue)
        em = np.sum(wi * yi)
        ems = np.append(ems, np.array([[em, 1 - em, thre]]), axis=0)
    ems = np.delete(ems, 0, axis=0)
    mins = np.min(ems, axis=0)
    if mins[1] < mins[0]:
        bem = mins[1]
        flag = 1
        a = np.where(ems[:, 1] == mins[1])
    else:
        bem = mins[0]
        a = np.where(ems[:, 0] == mins[0])
    if bem<=0:
        print('bem小于等于零了怎么办？可能是wi没有归一化')
    cm = math.log((1 - bem) / bem)
    minem = np.array([[bem, flag, cm, ems[:, 2][a[0][0]]]])
    return minem


def qfen(values, wi,testnum):
    params = Params()
    minems = np.ones((1, 4))
    for i in range(values.shape[0]):
        #if i < 100:
            if (i % 1000) == 0:
                print('正在计算第', i, '个特征值')
                print('正在计算第', testnum, '个弱分类器')
            value = values[i]
            minem = rfen(value, wi)
            # minem = np.array([[em，flag，cm，thres]])
            minems = np.append(minems, minem, axis=0)
    minems = np.delete(minems, 0, axis=0)
    minem = np.where(minems[:, 0] == np.min(minems[:, 0]))
    # 如果有多个最小误差的haar特征值，取第一个。
    # print('minem:', minem[0][0])
    # print(minems[minem[0][0], :])
    # print('*******************')
    num = minem[0][0]
    return np.append(minems[num, :], minem[0][0])


def dab(values):
    params = Params()
    rfens=np.ones((1,5))
    wi = np.ones((1, values.shape[1])) / (params.numPos + params.numNeg)
    for i in range(params.M):
        # minem = np.array([[em，flag，cm，thres,]]) 加上一个haar特征值的num
        minem = qfen(values, wi,i)
        rfens=np.append(rfens,np.array([minem]),axis=0)
        print('误差:',minem[0])
        # 更新wi
        if minem[2] == 0:
            break
        value = values[int(minem[4]), :]
        # getyi(value, flag, thre):
        yi = getyi(value, minem[1], minem[3])
        wi=wi*np.exp(minem[2]*yi)
        wi=wi/np.sum(wi)
    rfens=np.delete(rfens,0,axis=0)
    print(rfens)


def main():
    params = Params()
    values = np.zeros((params.numNeg + params.numPos, params.haar1num))
    for i in range(params.numPos):
        dir = './face/' + str(i) + '.jpg'
        valuelist = GetValueHaar1(dir)
        print('得到正样本' + str(i) + '图片的value')
        values[i] = valuelist
    for i in range(params.numNeg):
        dir = './nface/' + str(i) + '.jpg'
        valuelist = GetValueHaar1(dir)
        print('得到负样本' + str(i) + '图片的value')
        values[params.numPos + i] = valuelist
    values = values.T
    dab(values)


if __name__ == '__main__':
    main()
