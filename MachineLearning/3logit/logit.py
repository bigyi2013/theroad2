import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets


class logit(object):
    def __init__(self, data, y):
        self.x = data
        self.y = y
        self.n = self.x.shape[1]
        self.w = np.random.random(self.n).reshape(1, self.n)
        self.b = np.random.random()

    def wx(self):
        return np.dot(self.w, self.x.T) + self.b

    def p1(self):
        return np.exp(self.wx()) / (1 + np.exp(self.wx()))

    def cost(self):
        return -self.y * (self.wx()) + np.log(1 + np.exp(self.wx()))

    def cost_sum(self):
        return np.sum(self.cost())

    def yijiedao(self):
        return -self.x * (self.y - self.p1()).T

    def yijiedaob(self):
        return np.sum(-1 * (self.y - self.p1()))

    def yijiedao_sum(self):
        return np.sum(self.yijiedao(), axis=0)

    def erjiedao(self):
        return np.sum(np.dot(self.x, self.x.T) * self.p1() * (1 - self.p1()))
    def predict(self,x):
        return np.dot(self.w,x.T) + self.b

def sigmoid(x):
    return 1 / (1 + np.exp(-x))


if __name__ == '__main__':
    iris = datasets.load_iris()
    data = iris.data
    iris.target[100:150] = 1
    rand1 = np.random.randint(1, 150, 100)
    rand2 = np.random.randint(1, 150, 50)
    x1 = data[rand1]
    y1 = iris.target[rand1]
    x2 = data[rand2]
    y2 = iris.target[rand2]
    a = logit(data, iris.target)
    for i in range(10000):
        old_w = a.w
        a.w = a.w - a.yijiedao_sum()/ a.erjiedao()
        old_b = a.b
        a.b = a.b -a.yijiedaob() / a.erjiedao()
    print('w:', a.w)
    print('\n')
    print('b:', a.b)
    print('*' * 25)

