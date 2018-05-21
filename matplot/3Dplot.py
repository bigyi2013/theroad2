# -*- coding: utf-8 -*-
"""
Created on Thu May 17 19:50:38 2018

@author: yehoo
"""
import numpy as np
from mpl_toolkits.mplot3d import axes3d
import matplotlib.pyplot as plt
def kernelTrans(X, A,the): #calc the kernel or transform data to a higher dimensional space
    m,n = np.shape(X)
    K = np.mat(np.zeros((m,1)))
    for j in range(m):
        deltaRow = X[j,:] - A
        K[j] = np.dot(deltaRow,deltaRow.T)
    K = np.exp(K/(-1*the**2)) #divide in NumPy is element-wise not matrix like Matlab
    return K

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Grab some test data.
X, Y, Z = axes3d.get_test_data(0.05)
m,n=np.shape(X)
K = np.mat(np.zeros((m,m)))
for i in range(m):
    K[:,i] = kernelTrans(X,X[i,:], 1.5)
# Plot a basic wireframe.
ax.plot_wireframe(X, Y, K, rstride=10, cstride=10)

plt.show()