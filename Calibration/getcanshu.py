import numpy as np
import time
import cv2
def getv12(h):
    v12= np.array([h[0,0]*h[0,1],h[0,0]*h[1,1]+h[1,0]*h[0,1],h[1,0]*h[1,1],h[2,0]*h[0,1]+h[0,0]*h[2,1],h[2,0]*h[1,1]+h[1,0]*h[2,1],h[2,1]*h[2,1]])
    v11= np.array([h[0,0]*h[0,0],h[0,0]*h[1,0]+h[1,0]*h[0,0],h[1,0]*h[1,0],h[2,0]*h[0,0]+h[0,0]*h[2,0],h[2,0]*h[1,0]+h[1,0]*h[2,0],h[2,0]*h[2,0]])
    v22= np.array([h[0,1]*h[0,1],h[0,1]*h[1,1]+h[1,1]*h[0,1],h[1,1]*h[1,1],h[2,1]*h[0,1]+h[0,1]*h[2,1],h[2,1]*h[1,1]+h[1,1]*h[2,1],h[2,1]*h[2,1]])
    v1 = np.vstack((v12, v11 - v22))
    return v1

    svd=np.linalg.svd(v)
    b=svd[2][5]
    print('svd:',svd)
    return b
b=v()
print('b:',b,'\n')
B=np.array([(b[0],b[1],b[3]),(b[1],b[2],b[4]),(b[3],b[4],b[5])])
print('B:',B,'\n')
# A=np.linalg.cholesky(B)
# print('A:',np.linalg.inv(A.T))
V=(b[1]*b[3]-b[0]*b[4])/(b[0]*b[2]-b[1]*b[1])
print('V:',V,'\n')
lanmuda=b[5]-(b[3]*b[3]+V*(b[1]*b[3]-b[0]*b[4]))/b[0]
print('lanmuda:',lanmuda,'\n')

alpha=np.sqrt(lanmuda/b[0])
print('alpha:',alpha)
beita=np.sqrt((lanmuda*b[0])/(b[0]*b[2]-b[1]*b[1]))
gama=-b[1]*alpha*alpha*beita/lanmuda
u0=gama*V/beita-b[3]*alpha*alpha/lanmuda
print(V,u0,alpha,beita,lanmuda,gama)
