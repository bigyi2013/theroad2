import cv2
import numpy as np
import time
import threading


class Params(object):
    def __init__(self):
        self.numPos = 3
        self.numNeg = 3
        self.numStages = 0
        self.imgsize = (24, 24)
        self.haar1num = 33396


# def oldhaar1(x, y, w, h, img):
#     # haar1 定义为上下结构 ，上面是黑块，下面是白块
#     a = ([y,x], [y,x+w], [int(y + h / 2),x], [ int(y + h / 2),x + w], [ y + h,x], [y + h,x+w])
#     # 标准化检测框内图像
#     sum = np.sum(img[a[0][0]:a[5][0], a[0][1]:a[5][1]])
#     square = np.sum(np.square(img[a[0][0]:a[5][0], a[0][1]:a[5][1]]))
#     mean = sum / (w * h)
#     sqmean = square / (w * h)
#     varnormfactor = np.sqrt(abs(mean * mean - sqmean))
#     # 白块减黑块
#     sum1 = np.sum(img[a[2][0]:a[5][0], a[2][1]:a[5][1]])
#     sum2 = np.sum(img[a[0][0]:a[3][0], a[0][1]:a[3][1]])
#     featurevalue = float(sum1) - float(sum2)
#     normvalue = featurevalue / varnormfactor
#     return normvalue
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


def dab(values):
    # values.T 的格式是33396行、numpos+numneg列的矩阵。
    params = Params()
    values = values.T
    wi = np.ones((1, values.shape[1])) / (params.numPos + params.numNeg)
    lables = np.append(np.ones((1, params.numPos), dtype=np.int), np.zeros((1, params.numNeg), dtype=np.int))
    # ems的格式是[ 阈值，flag=0/1，minerror]
    ems = np.ones((1, 3))
    for i in range(values.shape[0]):
        if (i % 1000) == 0:
            print('正在计算第', i, '个特征值')
        value = values[i]
        arg = np.argsort(value)
        lables1 = lables[arg]
        #我发现了一种更快速的求误差的方法，可惜这里地方太小，写不开了。
        em = np.array([])
        for j in range(len(value)):
            lables2 = np.append(np.ones((1, j), dtype=np.int), np.zeros((1, len(value) - j), dtype=np.int))
            # lables3 = np.append(np.zeros((1, j), dtype=np.int), np.ones((1, len(value) - j), dtype=np.int))
            # lables1^lables2 表示大于等于阈值(value(j))为正样本
            # print('^:',lables1^lables2)
            # lables1^lables3 表示小于等于阈值为正样本
            # print('not ^:', lables1 ^ lables3)
            em1 = sum(np.dot(wi, lables1 ^ lables2))
            em = np.append(em, [em1, 1 - em1])
        thresnum = np.where(em == np.min(em))
        # 阈值就是value[j],j就是thresnum[0][0]//2，
        # thresnum[0][0]%2 为0，代表大于等于阈值为正，
        # thresnum[0][0]%2 为1，代表大于等于阈值为负，
        aaa = np.array([[value[arg[thresnum[0][0] // 2]], thresnum[0][0] % 2, np.min(em)]])
        ems = np.append(ems, aaa, axis=0)
    ems = np.delete(ems, 0, axis=0)
    ems2 = ems[:, 2]
    top0 = np.where(ems2 == np.min(ems2))
    print('天才？还是竖子？:', ems[top0])
    print(ems[top0].shape)
    print('top[0]:', top0[0])
    ruofenlei(values[top0[0]], ems[top0])


def ruofenlei(values, thres):
    print(values.shape)
    # 取第一个thres作为最优分类器。虽然其他分类器可能和第一个thres一样优秀，但是这就是命运啊。
    thre = thres[0]
    value = values[0]
    # thres[1]为0，代表大于等于阈值为正，
    # thres[1]为1，代表大于等于阈值为负，
    print('flag:', thre[1])
    print('阈值', thre[0])
    if thre[1] == 0:
        newvalue = np.array([value >= thre[0]])
    else:
        newvalue = np.array([value < thre[0]])
    print('newvalue:', newvalue)
    print(newvalue.shape)
    ones = np.ones((1, newvalue.shape[1]), dtype=np.int)
    print('ones', ones * newvalue)


def gab(values):
    # values 的格式是33396行、numpos+numneg列的矩阵。
    for i in range(values.shape[0]):
        value = values[i]


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
    dab(values)


if __name__ == '__main__':
    main()
