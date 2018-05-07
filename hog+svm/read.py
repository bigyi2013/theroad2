import numpy as np
import matplotlib.pyplot as plt

hang=np.zeros((1,3))
n=np.ones((1,3))
with open('./fourclass_scale.txt', 'r') as f:
    for i in f.readlines():
        for j in i.split():
            if len(j.split(':'))==1:
                hang[0,0]=j
            elif len(j.split(':'))==2:
                if int(j.split(':')[0])==1:
                    hang[0,1]=j.split(':')[1]
                elif int(j.split(':')[0])==2:
                    hang[0,2]=j.split(':')[1]
                else:
                    print('发生了意想不到的情况')
                    print(j)
                    print(type(j.split(':')[0]))
        n=np.append(n,hang,axis=0)
    n=np.delete(n,0,axis=0)
y=n[:,0]
x=n[:,1:3]
ct=np.where(n[:,0]==1)
cf=np.where(n[:,0]==-1)
plt.scatter(x[:,0][ct[0]],x[:,1][ct[0]], marker='^', c='r')
plt.scatter(x[:,0][cf[0]],x[:,1][cf[0]], marker='o', c='b')
plt.show()

