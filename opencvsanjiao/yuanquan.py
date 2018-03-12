import numpy as np
import cv2
import random
name="yuanquan.jpg"
for i in range(1,2000):
    # Create a black image
    img = np.zeros((512,512,3), np.uint8)
    # Draw a diagonal blue line with thickness of 5 px
    num=random.randint(2,5)
    for num1 in range(1,num):
        qidianx=random.randint(20,500)
        qidiany=random.randint(20,500)
        zhongdianx = random.randint(20, 500)
        zhongdiany = random.randint(20, 500)
        length=random.randint(50,100)
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        cv2.circle(img,(qidianx,qidiany),length,(cor,cor,cor),1)# -1表示实心 1代表虚心
        length2=5
        cv2.circle(img, (qidianx, qidiany), length2, (0, 255, 0), -1)
        cv2.imwrite(str('yuanquan2/')+str(i)+name,img)
        with open('yuanquan2/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(length)+'\n')

