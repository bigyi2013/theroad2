import numpy as np
import cv2
import random
name="zhengfang.png"
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
        dingdianx = random.randint(20, 500)
        dingdiany = random.randint(20, 500)
        cor = random.randint(10, 220)
        width=random.randint(2,8)
        pts = np.array([[qidianx,qidiany], [zhongdianx, zhongdianx], [dingdianx, dingdiany], ], np.int32)
        pts = pts.reshape((-1, 1, 2))
        cv2.polylines(img, [pts], True, (cor,cor,cor))
        cv2.imwrite(str('zhengfangxing/')+str(i)+name,img)
        with open('zhengfangxing/test.txt', 'a') as f:
            f.write(str(i)+":"+str(qidianx)+","+str(qidiany)+","+str(zhongdianx)+","+str(zhongdiany)+","+str(dingdianx)+","+str(dingdiany)+'\n')

