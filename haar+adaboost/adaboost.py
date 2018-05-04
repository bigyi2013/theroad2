import numpy as np
import cv2


class Params(object):
    def __init__(self):
        self.numPos = 100
        self.numNeg = 100
        self.numStages = 0
        self.imgsize = (24, 24)
        self.haar1num = 33396


# rfen= em，flag，cm，thres, 加上一个haar特征值的num
rfen = np.array([[2.17500000e-01, 0.00000000e+00, 1.28029507e+00, 1.20962804e+01,
                  2.08900000e+03],
                 [2.12717124e-01, 1.00000000e+00, 1.30862439e+00, 1.06841487e+01,
                  3.09100000e+03],
                 [2.13108521e-01, 1.00000000e+00, 1.30628883e+00, -1.32331266e+01,
                  1.42620000e+04],
                 [2.42411843e-01, 1.00000000e+00, 1.13950180e+00, -4.25737888e+00,
                  1.71690000e+04],
                 [2.54143061e-01, 0.00000000e+00, 1.07663647e+00, 1.47452443e+01,
                  2.26990000e+04],
                 [2.74085736e-01, 1.00000000e+00, 9.73990952e-01, 1.53383179e+01,
                  1.82460000e+04],
                 [2.56141775e-01, 0.00000000e+00, 1.06611936e+00, 1.40868544e+00,
                  3.18610000e+04],
                 [2.78988940e-01, 1.00000000e+00, 9.49482336e-01, 5.61589163e-01,
                  2.90400000e+03],
                 [2.88659214e-01, 1.00000000e+00, 9.01904819e-01, -9.88225855e-01,
                  1.49600000e+03],
                 [2.85929557e-01, 1.00000000e+00, 9.15236142e-01, -5.74191336e-02,
                  3.19550000e+04],
                 [2.91380239e-01, 0.00000000e+00, 8.88690001e-01, 2.43219203e+00,
                  1.01520000e+04],
                 [2.99963893e-01, 1.00000000e+00, 8.47469805e-01, -2.40023648e+00,
                  1.95210000e+04],
                 [2.77907381e-01, 1.00000000e+00, 9.54865516e-01, 4.74115442e+00,
                  1.96350000e+04],
                 [2.98078330e-01, 0.00000000e+00, 8.56465512e-01, -7.94900048e+00,
                  3.02910000e+04],
                 [2.88593739e-01, 0.00000000e+00, 9.02223709e-01, 3.18526302e+00,
                  2.37120000e+04],
                 [2.82976497e-01, 1.00000000e+00, 9.29744775e-01, 2.51732182e+00,
                  3.33800000e+04],
                 [2.78985365e-01, 1.00000000e+00, 9.49500111e-01, -7.83838161e+00,
                  2.37310000e+04],
                 [2.82098996e-01, 0.00000000e+00, 9.34073623e-01, 2.17218623e+00,
                  1.48390000e+04],
                 [2.81431599e-01, 1.00000000e+00, 9.37371470e-01, -4.22974697e+00,
                  2.24700000e+03],
                 [3.00126759e-01, 0.00000000e+00, 8.46694319e-01, 1.28173475e+01,
                  2.33860000e+04]])


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
    # flag=0 ,定义为大于阈值为正
    params = Params()
    ones = np.ones((1, params.numPos + params.numNeg), dtype=np.int)
    fuyis = ones * (-1)
    if flag == 0:
        newvalue = np.array([value > thre])
    else:
        newvalue = np.array([value <= thre])
    # 注意这里logical_xor是异或。
    # newvalue与ones不相等时，yi置1.
    yi1 = ones * newvalue
    yi2 = fuyis * np.logical_not(newvalue)
    yi = yi1 + yi2
    # 这里设定弱分类器把样本分类为正时置1，分类为负时置-1.
    return yi


def fenxi(result):
    params = Params()
    ones = np.ones((1, params.numPos + params.numNeg), dtype=np.int)
    lables = np.append(np.ones((1, params.numPos), dtype=np.int),
                       np.zeros((1, params.numNeg), dtype=np.int))
    resultTF = np.array([result > 0])
    result01 = ones * resultTF
    TF01 = ones * np.logical_not(np.logical_xor(lables, result01))
    em = np.sum(TF01) / (params.numPos + params.numNeg)
    print(em)


def test(rfens, values):
    params = Params()
    # rfen= em，flag，cm，thres, 加上一个haar特征值的num
    result = np.zeros((1,  params.numPos + params.numNeg))
    i = 0
    for rfen in rfens:
        i = i + 1
        flag = rfen[1]
        cm = rfen[2]
        thre = rfen[3]
        num = int(rfen[4])
        yi = getyi(values[num, :], flag, thre)
        cm_yi = cm * yi
        result = result + cm_yi
        print('——————第', i, '号弱分类器部署完毕——————')
    fenxi(result)


def getvalues():
    params = Params()
    values = np.zeros((params.numNeg + params.numPos, params.haar1num))
    for i in range(params.numPos):
        j=i+200
        dir = './face/' + str(j) + '.jpg'
        valuelist = GetValueHaar1(dir)
        print('------正在对第' + str(i) + '号正样本进行分析------')
        values[i] = valuelist
    for i in range(params.numNeg):
        j=i+200
        dir = './nface/' + str(j) + '.jpg'
        valuelist = GetValueHaar1(dir)
        print('------正在对第' + str(i) + '号负样本进行分析------')
        values[params.numPos + i] = valuelist
    values = values.T
    print('==========启动折跃引擎==========')
    test(rfen, values)


if __name__ == '__main__':
    getvalues()
