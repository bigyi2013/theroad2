import  numpy as np
def kernelTrans(X, A,the): #calc the kernel or transform data to a higher dimensional space
    m,n = np.shape(X)
    K = np.mat(np.zeros((m,1)))
    for j in range(m):
        deltaRow = X[j,:] - A
        K[j] = np.dot(deltaRow,deltaRow.T)
    K = np.exp(K/(-1*the**2)) #divide in NumPy is element-wise not matrix like Matlab
    return K
x=np.array([[1,2,2],[1,3,1]])
print(type(x))
print(np.shape(x))
y=x[0,:]
print(type(y))
print(np.shape(y))
k=kernelTrans(x,y,1)
print(k)
