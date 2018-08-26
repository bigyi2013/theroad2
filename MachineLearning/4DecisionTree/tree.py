from dataset import createDataSet2 as mydata
import numpy as np
import pandas as pd
import math
def count_ent(num,n):
    if num==0:
        return 0
    else:
        return (num/n)*math.log2(num/n)


def count_gain(x, y):
    Set = set(x)
    ent=0
    gain=0
    for i in Set:
        a = np.where(x == i)
        n=len(a[0])
        p_num=len(np.where(y[a[0]]=="好瓜")[0])
        n_num=n-p_num
        ent=-count_ent(p_num,n)-count_ent(n_num,n)
        gain=gain+(n/len(x))*ent
    return gain


if __name__ == '__main__':
    dataSet, labels, labels_full = mydata()
    data = np.array(dataSet)
    data = data.T
    X = data[:-1]
    Y = data[-1]
    for i in X:
        gain=count_gain(i,Y)
        print(gain)

