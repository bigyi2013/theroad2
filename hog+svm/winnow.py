# 决定自己写个数据集，因为不管是感知器还是winnow
# 能力都一般，所以对数据集的要求还是比较严格的。(线性可分)
# 虽然名字是winnow，但是内容是感知机，
import numpy as np
import matplotlib.pyplot as plt


def m():
    # W = np.array([-9, -7])
    W0 = 3
    W = np.random.randint(-9, 9, 2)
    X = np.random.random((100, 2)) * 2 - 1
    y = Y = 2 * np.array(W.dot(X.T) >= W0) - 1
    # w[0]*x1+w[1]*x2-5=0
    A = np.where(Y == 1)
    B = np.where(Y == -1)
    print('W:', W, W0)
    l = np.random.random((100, 2)) * 2 - 1
    theta = 0.01
    w0 = np.ones((1, X.shape[0]))
    w = np.random.randint(1, 5, 3)
    x = np.append(w0.T, X, axis=1)
    while True:
        num = 0
        for i in range(x.shape[0]):
            a = x[i, :]
            cy = y[i]
            hy = w.dot(a)
            theta = 0.1
            if (cy == 1 and hy < 0) or (cy == -1 and hy > 0):
                # 改变theta，可以改变更新速度
                # 这种更新方式，有时候找不到超平面，我把它保留的原因是这个更新方法和
                # 逻辑回归的更新方法类似，应该是巧合。
                # 逻辑回归中hy的取值是（0，1），永远在min(cy)到max(xy)之间
                w = w + (cy - hy) * a
                # 这种更新方式，能最大速度的更新权重，而且能保证找到超平面（如果有)
                # w = w + cy * a
                num = num + 1
                print('change:', num)
        print('w;', w)
        # 红色是1
        plt.scatter(X[A[0], 0], X[A[0], 1], c='r')
        # 蓝色是-1
        plt.scatter(X[B[0], 0], X[B[0], 1], c='b')
        plt.plot(X[:, 0], (W0 - W[0] * X[:, 0]) / W[1], c='#FFC0CB')
        plt.plot(l[:, 0], (-w[0] - w[1] * l[:, 0]) / w[2], c='g')
        # plt.show()


m()
