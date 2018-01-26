#之前写了一半的程序找不到了，所以重新开了一个
#
import numpy as np
import cv2
def getcorners(filename):
    img=cv2.imread(filename,0)
    patternsize=(13,12)
    found,corners=cv2.findChessboardCorners(img,patternsize)
    if found:
        criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
        corners2=cv2.cornerSubPix(img, corners, (11, 11),  (-1,-1),criteria)
        #print(corners2)
        #img2 = cv2.drawChessboardCorners(img, patternsize, corners2, found)
        #cv2.imshow('img2',img2)
        # print('-' * 10, '找到点了', '-' * 10)
        # print('麻烦看一下点是否吻合，按任意键继续')
        # key=cv2.waitKey(0)
        # if key:
        #     cv2.destroyAllWindows()
        return corners2
    else:print('没有找到点，真不敢相信')