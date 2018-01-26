
img=cv2.imread('Image20.tif')
cv2.circle(img,(int(ua),int(va)),5,(0,0,255,),-1)
cv2.circle(img, (int(ub), int(vb)), 5, (0, 0, 255),-1)
cv2.circle(img, (int(uc), int(vc)), 5, (0, 0, 255),-1)
cv2.imshow('img',img)
# print(xc, yc)
# print(uc, vc)
key=cv2.waitKey(0)