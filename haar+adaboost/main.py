import cv2
import numpy as np


class BEST(object):
    def __init__(self):
        self.type = 'haar'
        self.name = []
        self.berrors = []
        self.bthres = []


def haar1(x, y, w, h, img):
    # haar1 定义为上下结构 ，上面是黑块，下面是白块
    a = ([x, y], [x + w, y], [x, int(y + h / 2)], [x + w, int(y + h / 2)], [x, y + h], [x + w, y + h])
    # 标准化检测框内图像
    sum = np.sum(img[a[0][0]:a[5][0], a[0][1]:a[5][1]])
    square = np.sum(np.square(img[a[0][0]:a[5][0], a[0][1]:a[5][1]]))
    mean = sum / (w * h)
    sqmean = square / (w * h)
    varnormfactor = np.sqrt(abs(mean * mean - sqmean))
    # 白块减黑块
    featurevalue = np.sum(img[a[2][0]:a[5][0], a[2][1]:a[5][1]]) - np.sum(img[a[0][0]:a[3][0], a[0][1]:a[3][1]])
    normvalue = featurevalue / varnormfactor
    return normvalue


def haar2(x, y, w, h, img):
    # haar2定义为左右结构，左一是白块，左二是黑块，左三是白块
    a = ([x, y], [x + int(w / 3), y], [x + int(2 * w / 3), y], [x + w, y], [x, y + h], [x + int(w / 3), y + h],
         [x + int(2 * w / 3), y + h], [x + w, y + h])
    sum = np.sum(img[a[0][0]:a[7][0], a[0][1]:a[7][1]])
    square = np.sum(np.square(img[a[0][0]:a[7][0], a[0][1]:a[7][1]]))
    mean = sum / (w * h)
    sqmean = square / (w * h)
    varnormfactor = np.sqrt(abs(mean * mean - sqmean))

    # 左一白块加左三白块减两倍的左二黑块
    featurevalue = np.sum(img[a[0][0]:a[5][0], a[0][1]:a[5][1]]) + np.sum(
        img[a[2][0]:a[7][0], a[2][1]:a[7][1]]) - 2 * np.sum(img[a[1][0]:a[6][0], a[1][1]:a[6][1]])
    normvalue = featurevalue / varnormfactor
    return normvalue


def ruofenlei(values, numpos, numneg):
    best = BEST()
    values = values.T
    arg = np.argsort(values, axis=1)
    [x, y] = values.shape
    errors = np.ones((x, y - 1))
    w = np.ones((x, y)) * 1 / y
    for i in range(x):
        bname=0
        bthres = 0
        berrors = 10000
        for k in range((y - 1)):
            thres = (values[i, arg[i, k]] + values[i, arg[i, k + 1]]) / 2
            leftv1 = 0
            rightv1 = 0
            leftv2 = 0
            rightv2 = 0
            for j in range(k + 1):
                # leftvalue是从1到k的集合
                if arg[i, j] < numpos:
                    # 正样本
                    yi = 1
                else:
                    # 负样本
                    yi = 0
                leftv1 = leftv1 + w[i, arg[i, j]] * yi
                leftv2 = leftv2 + w[i, arg[i, j]]
            leftv = leftv1 / leftv2
            for j in range(k, numpos + numneg):
                # rightvalue是从1到k的集合
                if arg[i, j] < numpos:
                    # 正样本
                    yi = 1
                else:
                    # 负样本
                    yi = 0
                rightv1 = rightv1 + w[i, arg[i, j]] * yi
                rightv2 = rightv2 + w[i, arg[i, j]]
            rightv = rightv1 / rightv2
            # 接下来是计算error
            errorleft = 0
            errorright = 0
            for j in range(k + 1):
                if arg[i, j] < numpos:
                    yi = 1
                if arg[i, j] >= numpos:
                    # 负样本
                    yi = 0
                errorleft = errorleft + w[i, arg[i, j]] * (yi - leftv) * (yi - leftv)
            for j in range(k, numpos + numneg):
                if arg[i, j] < numpos:
                    yi = 1
                if arg[i, j] >= numpos:
                    # 负样本
                    yi = 0
                errorright = errorright + w[i, arg[i, j]] * (yi - rightv) * (yi - rightv)
            errors[i, k] = errorright + errorleft
            if errors[i, k] <= berrors:
                berrors = errors[i, k]
                bthres = thres
                bname=i
        best.berrors.append(berrors)
        best.bthres.append(bthres)
        best.name.append(bname)
        print(berrors)
        berrors=10000
        print('特征值',i)
        print(np.min(best.berrors))
    return best


def getvalues(dir, num):
    valuelist = np.array([])
    img = cv2.imread(dir, 0)
    imgsize = (24, 24)
    for x in range(0, imgsize[0] + 1):
        for y in range(0, imgsize[1] + 1):
            for w in range(1, imgsize[0] + 1):
                for h in range(2, imgsize[1] + 2, 2):
                    if (x + w) < (imgsize[0] + 1) and (y + h) < (imgsize[1] + 1):
                        # haar定义参数：haar1(x,y,w,h,img)
                        value = haar1(x, y, w, h, img)
                        valuelist = np.append(valuelist, value)
    valuelist = np.reshape(valuelist, (1, num))
    return valuelist


def main():
    num = 43200
    numpos = 1000
    numneg = 1000
    values = np.zeros((1, num))
    for i in range(numpos):
        # 正样本1
        dir = './face/' + str(i) + '.jpg'
        valuelist = getvalues(dir, num)
        print('得到正样本' + str(i) + '图片的value')
        values = np.append(values, valuelist, axis=0)
    for i in range(numneg):
        # 负样本
        dir = './nface/' + str(i) + '.jpg'
        valuelist = getvalues(dir, num)
        print('得到负样本' + str(i) + '图片的value')
        values = np.append(values, valuelist, axis=0)
    # 删除valus的第一行（第一行啊，全是零）
    values = np.delete(values, 0, axis=0)
    arg = ruofenlei(values, numpos, numneg)


main()
