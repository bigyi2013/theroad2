from getcorners import getcorners
from homography1 import homography
import  math
import cv2
import numpy as np
class image(object):
    def __init__(self, name,size=[0,0],r=[0,0,0],t=[0,0,0,]):
        self.name = name
        self.px=30
        self.py=30
        self.row = size[0]
        self.col = size[1]
        self.size=size
        # self.h=self.geth()
        self.r=r
        self.t=t
        self.corner=getcorners(self.name,self.size)
    def draw(self,num=[]):
        img = cv2.imread(self.name)
        corners=self.corner
        for i in num:
            ua = corners[i][0][0]
            va = corners[i][0][1]
            obj=self.getobjlist()
            print(obj[i])
            print(ua,va)
            cv2.circle(img, (int(ua), int(va)), 5, (0, 0, 255,), -1)
            cv2.imshow('img', img)
            key = cv2.waitKey(0)
        return
    def geth(self,points=[]):
        self.corner=getcorners(self.name,self.size)
        corners=self.corner
        objlist=self.getobjlist(points)
        if len(points)==0:
            cornerslist=corners
        else:

            cornerslist=[]
            for i in points:
                cornerslist.append(corners[i])
        h=homography(cornerslist,objlist)
        return h/h[8]
    def getobjlist(self,points=[]):
        objlist=[]
        if len(points)==0:
            for x in range(self.col):
                for y in range(self.row):
                    objlist.append([y*self.px,x*self.py])
        else:

                #这个函数不能用，只能让points==0时候可以。
                for xy in points:
                    y=xy%(self.col-1)
                    x=int(xy/(self.col-1))
                    objlist.append([y*self.px,x*self.py])
        return objlist

    def getv(self,points=[]):
        h = self.geth(points)
        v12 = np.array(
            [h[0] * h[1], h[3] * h[1] + h[0] * h[4], h[3] * h[4], h[6] * h[1] + h[0] * h[7], h[6] * h[4] + h[3] * h[7],
             h[6] * h[7]])
        v11 = np.array(
            [h[0] * h[0], h[0] * h[3] + h[3] * h[0], h[3] * h[3], h[0] * h[6] + h[6] * h[0], h[6] * h[3] + h[3] * h[6],
             h[6] * h[6]])
        v22 = np.array(
            [h[1] * h[1], h[1] * h[4] + h[4] * h[1], h[4] * h[4], h[7] * h[1] + h[1] * h[7], h[7] * h[4] + h[4] * h[7],
             h[7] * h[7]])
        v = np.vstack((v12, v11 - v22))
        return v
size=[12,13]
filename='Image11.tif'
image1=image(filename,size)
filename='Image17.tif'
image2=image(filename,size)
filename='Image20.tif'
image3=image(filename,size)
points=[ 1,11,23,36,41,57,73,88,98,115,140]
image1.draw(points)
image2.draw(points)
image3.draw(points)
h1=image1.geth(points)
h2=image2.geth(points)
h3=image3.geth(points)
print('h1:',h1)

v1=image1.getv(points)
v2=image2.getv(points)
v3=image3.getv(points )
v=np.vstack((v1,v2,v3))
svd = np.linalg.svd(v)
b = svd[2][5]
V=(b[1]*b[3]-b[0]*b[4])/(b[0]*b[2]-b[1]*b[1])
lanmuda=b[5]-(b[3]*b[3]+V*(b[1]*b[3]-b[0]*b[4]))/b[0]
alpha=np.sqrt(lanmuda/b[0])
beita=np.sqrt((lanmuda*b[0])/(b[0]*b[2]-b[1]*b[1]))
gama=-b[1]*alpha*alpha*beita/lanmuda
u0=gama*V/beita-b[3]*alpha*alpha/lanmuda
print(V,u0,alpha,beita,lanmuda,gama)

