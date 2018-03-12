import numpy as np
import cv2
import random
name="zhengfang.png"
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
        dingdianx = random.randint(20, 500)
        dingdiany = random.randint(20, 500)
        if(qidianx==zhongdianx):
            break
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        cv2.rectangle(img, (qidianx, qidiany), (zhongdianx, zhongdiany), (cor,cor,cor), -1)  # -1表示实心
        length=5
        cv2.circle(img, (qidianx, qidiany), length, (0, 255, 0), -1)
        cv2.circle(img, (zhongdianx, zhongdiany), length, (0, 255, 0), -1)
        cv2.circle(img, (qidianx,zhongdiany), length, (0, 255, 0), -1)
        cv2.circle(img, (zhongdianx, qidiany), length, (0, 255, 0), -1)
        cv2.imwrite(str('zhengfangxing/')+str(i)+name,img)
        with open('zhengfangxing/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(zhongdianx)+","+str(zhongdiany)+","+str(dingdianx)+","+str(dingdiany)+'\n')

