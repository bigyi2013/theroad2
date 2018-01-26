import cv2
img1=cv2.imread('opencv.jpg')
img2=cv2.imread('1.jpg')
i=300
img3=img2[300:600,300:544]
cv2.imshow('img3',img3)
l=range(1,100)
m=[]
for u in l:
    m.append(u)
for u in l:
    m.append(100-u)

while True:
    for x in m:
        x=x/100
        print(x)
        dst=cv2.addWeighted(img1,x,img3,1-x,0)
        cv2.imshow('sdt',dst)
        key=cv2.waitKey(1)
        if key==27:
            i=1
            break
    if i==1:
        break
cv2.destroyAllWindows()