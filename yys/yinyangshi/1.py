from  jieping import window_capture
import cv2
import numpy as np
def cap():
    window_capture()
def find(template):
    w, h = template.shape[::-1]
    img=cv2.imread("save.jpg",0)
    res = cv2.matchTemplate(img,template,cv2.TM_CCOEFF_NORMED)
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(res)
    top_left = max_loc
    # bottom_right = (top_left[0] + w, top_left[1] + h)
    # cv2.rectangle(img,top_left, bottom_right, 255, 2)
    # cv2.imshow("img",img)
    # cv2.waitKey(0)
    return top_left
img=cv2.imread("1.png",0)
cap()
find(img)
