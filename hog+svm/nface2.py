import os
import cv2

dir='./nface'
my_list=os.listdir(dir)
for i in range(0,len(my_list)):
    path=os.path.join(dir,my_list[i])
    print(path)
    img=cv2.imread(path,0)
    NFace64=cv2.resize(img,(64,128))
    cv2.imwrite(str('./nface64/')+str(i)+'.jpg',NFace64)





