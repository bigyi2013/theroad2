import numpy as np
import cv2
import random
name="tuoyuan.png"
for i in range(1,500):
    # Create a black image
    img = np.zeros((512,512,3), np.uint8)
    # Draw a diagonal blue line with thickness of 5 px
    num=random.randint(2,5)
    for num1 in range(1,num):
        qidianx=random.randint(20,500)
        qidiany=random.randint(20,500)
        zhongdianx = random.randint(20, 500)
        zhongdiany = random.randint(20, 500)
        length=random.randint(20,100)
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        angle=random.randint(0,360)
        bianle=random.randint(1,5)
        cv2.ellipse(img,(qidianx, qidiany),(length,length/bianle),angle,0,360,(cor,cor,cor),width,-1)
        cv2.imwrite(str('tuoyuan/')+str(i)+name,img)
        with open('tuoyuan/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(length)+'\n')

