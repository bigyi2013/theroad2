import numpy as np
import cv2
import juzhen2
from getcorners import  getcorners
def getxy(a):
    y=(a-1)//13+1
    x=a%13
    x,y=juzhen2.xy(x,y)
    return x,y
def geth(a,b,c,corners,filename):
    img = cv2.imread(filename)
    ua,va =juzhen2.uv(a,corners)
    xa,ya=getxy(a)
    ub, vb = juzhen2.uv(b,corners)
    xb, yb = getxy(b)
    uc, vc = juzhen2.uv(c,corners)
    xc, yc = getxy(c)
    # ud, vd = juzhen2.uv(d,corners)
    # xd, yd = getxy(d)
    uv=np.array([(ua,ub,uc),(va,vb,vc),(1,1,1)])
    xy=np.array([(xa,xb,xc),(ya,yb,yc),(1,1,1)])
    xyrank=np.linalg.matrix_rank(xy)
    uvrank=np.linalg.matrix_rank(uv)
    h=np.dot(uv,np.linalg.pinv(xy))

    #*************画点
    # va2=-(va-964)
    # vb2 = -(vb - 964)
    # vc2 = -(vc - 964)
    # cv2.circle(img,(int(ua),int(va)),5,(0,0,255,),-1)
    # cv2.circle(img, (int(ub), int(vb)), 5, (0, 0, 255),-1)
    # cv2.circle(img, (int(uc), int(vc)), 5, (0, 0, 255),-1)
    # cv2.imshow('img',img)
    # # print(xc, yc)
    # # print(uc, vc)
    # key=cv2.waitKey(0)
    # #*****************
    return h ,xyrank ,uvrank
