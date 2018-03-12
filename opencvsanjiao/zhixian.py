import numpy as np
import cv2
import random
name="zhixian.jpg"
for i in range(1,2000):
    # Create a black image
    img = np.zeros((512,512,3), np.uint8)
    # Draw a diagonal blue line with thickness of 5 px
    num=random.randint(2,5)
    qidianx = random.randint(20, 500)
    qidiany = random.randint(20, 500)
    for num1 in range(1,num):
        zhongdianx = random.randint(20, 500)
        zhongdiany = random.randint(20, 500)
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        length=8
        cv2.line(img,(qidianx,qidiany),(zhongdianx,zhongdiany),(cor,cor,cor),width)
        cv2.line(img, (qidianx, qidiany), (zhongdianx, zhongdiany), (cor, cor, cor), width)
        cv2.circle(img, (qidianx, qidiany), length, (0, 200, 0), -1)
        cv2.circle(img, (zhongdianx,zhongdiany), length, (0, 200, 0), -1)
        cv2.imwrite(str('zhixian3/')+str(i)+name,img)
        with open('zhixian3/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(zhongdianx)+","+str(zhongdiany)+'\n')

