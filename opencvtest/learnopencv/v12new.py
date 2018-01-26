import main
import cv2
import numpy as np
import time
def geth(filename):
    if filename=='Image11.tif':
        h=np.array([[     0.0870083437725901 , 0.931141668208053 ,162.179035600357],
[0.973421221029705 ,0.132601560164273 ,23.1626463045191],
[0.000679181473652625  ,2.54392294712377e-05 , 1]])
    elif filename=='Image17.tif':
        h=np.array( [[ 0.216252536675398	,1.18691280318395	,121.759079240640],[
1.36951169968034	,0.238851640004031,	56.2991388686579],[
0.00117445064544373,	-0.000323200587254749,	1]])
    else:h=np.array([[ 0.204443418359277,	1.52388686121524,	64.4428226818178],[
1.72168008509972	,-0.161253947178982	,96.6319163974618],[
0.00130108384539080,	0.00183328850902144,	1]])
    return h
def getv12(filename):
    h=geth(filename)
    #print(h,'\n')
    # v12= np.array([h[0,0]*h[1,0],h[0,0]*h[1,1]+h[0,1]*h[1,0],h[0,1]*h[1,1],h[0,2]*h[1,0]+h[0,0]*h[1,2],h[0,2]*h[1,1]+h[0,1]*h[1,2],h[0,2]*h[1,2]])
    # v11= np.array([h[0,0]*h[0,0],h[0,0]*h[0,1]+h[0,1]*h[0,0],h[0,1]*h[0,1],h[0,2]*h[0,0]+h[0,0]*h[0,2],h[0,2]*h[0,1]+h[0,1]*h[0,2],h[0,2]*h[0,2]])
    # v22= np.array([h[1,0]*h[1,0],h[1,0]*h[1,1]+h[1,1]*h[1,0],h[1,1]*h[1,1],h[1,2]*h[1,0]+h[1,0]*h[1,2],h[1,2]*h[1,1]+h[1,1]*h[1,2],h[1,2]*h[1,2]])
    v12= np.array([h[0,0]*h[0,1],h[0,0]*h[1,1]+h[1,0]*h[0,1],h[1,0]*h[1,1],h[2,0]*h[0,1]+h[0,0]*h[2,1],h[2,0]*h[1,1]+h[1,0]*h[2,1],h[2,0]*h[2,1]])
    v11= np.array([h[0,0]*h[0,0],h[0,0]*h[1,0]+h[1,0]*h[0,0],h[1,0]*h[1,0],h[2,0]*h[0,0]+h[0,0]*h[2,0],h[2,0]*h[1,0]+h[1,0]*h[2,0],h[2,0]*h[2,0]])
    v22= np.array([h[0,1]*h[0,1],h[0,1]*h[1,1]+h[1,1]*h[0,1],h[1,1]*h[1,1],h[2,1]*h[0,1]+h[0,1]*h[2,1],h[2,1]*h[1,1]+h[1,1]*h[2,1],h[2,1]*h[2,1]])
    return v11,v12,v22
def v():
    filename='Image11.tif'
    v11,v12,v22=getv12(filename)
    v1=np.vstack((v12,v11-v22))
    # print(v1)
    # print('*'*9)
    filename='Image17.tif'

    v11,v12,v22=getv12(filename)
    v2=np.vstack((v12,v11-v22))
#    print(v2)
#    print('*'*9)
    filename='Image20.tif'
    v11,v12,v22=getv12(filename)
    v3=np.vstack((v12,v11-v22))
    # print(v3)
    # print('*'*9)

    v=np.vstack((v1,v2,v3))
    #print(v)
    #print(np.linalg.matrix_rank(v))
    eigh=np.linalg.eigh(np.dot(v.T,v))
    print('eigh:',eigh)
    #print(np.dot(v.T,v))
    svd=np.linalg.svd(v)
    print('svd:',svd)
    b=svd[2][5]
    return b

b=v()
print('b:',b,'\n')
B=np.array([(b[0],b[1],b[3]),(b[1],b[2],b[4]),(b[3],b[4],b[5])])
print('B:',B,'\n')
# B=np.array([[  2.83281428e-07  , 0.00000000e+00 , -1.80849739e-04],
#  [  0.00000000e+00   ,3.14712679e-07 , -7.80457939e-05],
#  [ -1.80849739e-04  ,-7.80457939e-05 ,  1.13481093e+00]])
# b=np.array([2.83281428e-07, 0.00000000e+00,3.14712679e-07,-1.80849739e-04  ,-7.80457939e-05 ,  1.13481093e+00])
try:
    A=np.linalg.cholesky(B)
    print('A:',np.linalg.inv(A.T))
except:
    print('****')

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