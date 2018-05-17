from random import randint
import matplotlib.pyplot as plt
import numpy as np
import threading
from multiprocessing import Process
import os

class TrainDataLoader:
    def __init__(self):
        pass

    def draw(self,alphas):
        Y = self.y
        X = self.x
        W = self.w
        A = np.where(Y == 1)
        B = np.where(Y == -1)
        a=np.where(alphas!=0)
        plt.scatter(X[A[0], 0], X[A[0], 1], c='r')
        # 蓝色是-1
        plt.scatter(X[B[0], 0], X[B[0], 1], c='b')
        plt.scatter(X[a[0], 0], X[a[0], 1], c='y')
        plt.plot([0, 100], (-W[0] - W[1] * np.array([0, 100])) / W[2], c='#FFC0CB')
        plt.axis([0, 100, 0, 100])
        plt.show()

    def getW(self):
        # 这段代码用了一个小技巧，能写出来，我还有点小骄傲啊。
        W = np.random.randint(-9, 9, 2)
        if W[0] * W[1] == 0 or abs(W[0] / W[1]) > 3 or abs(W[0] / W[1]) < 0.33:
            W = self.getW()
            return W
        elif W[0] * W[1] > 0:
            # 同号, 与y轴相交与（0，0.8）
            W0 = -8 * W[1] / 10
        else:
            # 异号, 与y轴相交与（0，0.2）
            W0 = -  W[1] / 5
        W = np.append(100*W0, W)
        return W

    def GenerateRandomData(self, count):
        W = self.getW()
        X = np.random.random((count, 2))*100
        Y = []
        for i in range(X.shape[0]):
            real_value = W[1] * X[i][0] + W[2] * X[i][1] + W[0]
            if real_value > 0:
                Y.append(-1)
            else:
                Y.append(1)
        self.y = np.array(Y)
        self.x = X
        self.w = W
        return X, np.array(Y), W


class SimplePerceptron:
    def __init__(self, train_data, real_result, eta=1):
        self.w = np.zeros([1, len(train_data.T)], int)
        self.b = 0
        self.eta = eta
        self.train_data = train_data
        self.real_result = real_result

    def selectJrand(self, i, m):
        j = i  # we want to select any J not equal to i
        while (j == i):
            j = int(np.random.uniform(0, m))
        return j

    def clipAlpha(self, aj, H, L):
        if aj > H:
            aj = H
        if L > aj:
            aj = L
        return aj

    def smoSimple(self, dataMatIn, classLabels, C, toler, maxIter):
        dataMatrix = np.mat(dataMatIn)
        labelMat = np.mat(classLabels).transpose()
        b = 0
        m, n = np.shape(dataMatrix)
        alphas = np.mat(np.zeros((m, 1)))
        iter = 0
        while (iter < maxIter):
            alphaPairsChanged = 0
            for i in range(m):
                fXi = float(np.multiply(alphas, labelMat).T * (dataMatrix * dataMatrix[i, :].T)) + b
                Ei = fXi - float(labelMat[i])  # if checks if an example violates KKT conditions
                if ((labelMat[i] * Ei < -toler) and (alphas[i] < C)) or (
                        (labelMat[i] * Ei > toler) and (alphas[i] > 0)):
                    j = self.selectJrand(i, m)
                    fXj = float(np.multiply(alphas, labelMat).T * (dataMatrix * dataMatrix[j, :].T)) + b
                    Ej = fXj - float(labelMat[j])
                    alphaIold = alphas[i].copy()
                    alphaJold = alphas[j].copy()
                    if (labelMat[i] != labelMat[j]):
                        L = max(0, alphas[j] - alphas[i])
                        H = min(C, C + alphas[j] - alphas[i])
                    else:
                        L = max(0, alphas[j] + alphas[i] - C)
                        H = min(C, alphas[j] + alphas[i])
                    if L == H: print("L==H");continue
                    eta = 2.0 * dataMatrix[i, :] * dataMatrix[j, :].T - dataMatrix[i, :] * dataMatrix[i,
                                                                                           :].T - dataMatrix[j,
                                                                                                  :] * dataMatrix[j,
                                                                                                       :].T
                    if eta >= 0: print("eta>=0");continue
                    alphas[j] -= labelMat[j] * (Ei - Ej) / eta
                    alphas[j] = self.clipAlpha(alphas[j], H, L)
                    if (abs(alphas[j] - alphaJold) < 0.00001): print("j not moving enough");continue
                    alphas[i] += labelMat[j] * labelMat[i] * (alphaJold - alphas[j])  # update i by the same amount as j
                    # the update is in the oppostie direction
                    b1 = b - Ei - labelMat[i] * (alphas[i] - alphaIold) * dataMatrix[i, :] * dataMatrix[i, :].T - \
                         labelMat[j] * (alphas[j] - alphaJold) * dataMatrix[i, :] * dataMatrix[j, :].T
                    b2 = b - Ej - labelMat[i] * (alphas[i] - alphaIold) * dataMatrix[i, :] * dataMatrix[j, :].T - \
                         labelMat[j] * (alphas[j] - alphaJold) * dataMatrix[j, :] * dataMatrix[j, :].T
                    if (0 < alphas[i]) and (C > alphas[i]):
                        b = b1
                    elif (0 < alphas[j]) and (C > alphas[j]):
                        b = b2
                    else:
                        b = (b1 + b2) / 2.0
                    alphaPairsChanged += 1
                    print("iter: %d i:%d, pairs changed %d" % (iter, i, alphaPairsChanged))
            if (alphaPairsChanged == 0):
                iter += 1
            else:
                iter = 0
            print("iteration number: %d" % iter)
        print(np.where(np.array(alphas) != 0))
        return b, alphas


if __name__ == "__main__":
    # Init some parameters
    # gradient = 2
    # offset = 10
    point_num = 100
    train_num = 40
    loader = TrainDataLoader()
    x, y, w = loader.GenerateRandomData(point_num)
    perceptron = SimplePerceptron(x, y)
    # First training
    b, alphas=perceptron.smoSimple(x, y, 1, 0, train_num)
    b2, alphas2=perceptron.smoSimple(x, y, 1000, 0, train_num)
    print('alphas:',alphas)
    print('alphas:',alphas2)
    loader.draw(alphas)
    # perceptron.verify(test_data, test_real_result)
    # rint("T1: w:", perceptron.w," b:", perceptron.b)

    # Draw the figure
    # # 1. draw the (x,y) points
    # plt.plot(x, y, "*", color='gray')
    # plt.plot(x_t, y_t, "+")
    # # 2. draw y=gradient*x+offset line
    # plt.plot(x,x.dot(gradient)+offset, color="red")
    # # 3. draw the line w_1*x_1 + w_2*x_2 + b = 0
    # plt.plot(x, -(x.dot(float(perceptron.w.T[0]))+float(perceptron.b))/float(perceptron.w.T[1])
    #          , color='green')
    # plt.show()
