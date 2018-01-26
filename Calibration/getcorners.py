#之前写了一半的程序找不到了，所以重新开了一个
#
import numpy as np
import cv2
def getcorners(filename,size):
    img=cv2.imread(filename,0)
    patternsize=(size[0],size[1])
    found,corners=cv2.findChessboardCorners(img,patternsize)
    if found:
        criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
        corners2=cv2.cornerSubPix(img, corners, (11, 11),  (-1,-1),criteria)
        return corners2
    else:print('没有找到点，真不敢相信')