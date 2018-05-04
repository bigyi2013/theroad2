# -*- coding: utf-8 -*-
import cv2
import re
import os
num=0
for i in ['01','02','03','04','05','06','07','08','09','10']:
    f2 = open('./FDDB-folds/FDDB-fold-'+str(i)+'-ellipseList.txt', 'r')
    for face in f2.readlines():
        if re.match(r'.*img.*', face.strip()):
            name=face.strip()
        if re.match(r'.* 1$',face.strip()):
            area=face.strip()
            a=re.split(r'\s+', area)
            if len(a)==6:
                img=cv2.imread(str('./originalPics/')+name+str('.jpg'),0)
                a=list(map(int,map(float,a)))
                print(a)
                if int(a[0])>50 and  int(a[1])+1>50 and a[4]-int(a[0])>0 and a[3]-int(a[1])>0:
                    Face=img[a[4]+1-int(a[0]):a[4]+int(a[0]),a[3]+1-int(a[1]):a[3]+int(a[1])]
                    #Face24=cv2.resize(Face,(24,24))
                    #Face150=cv2.resize(Face24,(150,150))
                    #cv2.imshow('face',Face)
                    cv2.imwrite(str('./1face/')+str(num)+'.jpg',Face)
                    num+=1
                    print('Face+')
                cv2.waitKey()