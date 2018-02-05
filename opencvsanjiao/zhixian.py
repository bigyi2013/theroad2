import numpy as np
import cv2
import random
name="sanjiao.png"
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
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        cv2.line(img,(qidianx,qidiany),(zhongdianx,zhongdiany),(cor,cor,cor),width)
        cv2.imwrite(str('zhixian/')+str(i)+name,img)
        with open('zhixian/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(zhongdianx)+","+str(zhongdiany)+'\n')

