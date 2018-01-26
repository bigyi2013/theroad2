import numpy as np
import cv2
import glob

# termination criteria
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)
cbrow = 11
cbcol = 8
# prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
objp = np.zeros((cbrow * cbcol,3), np.float32)
objp[:,:2] = np.mgrid[0:cbcol,0:cbrow].T.reshape(-1,2)
objp=objp
# Arrays to store object points and image points from all the images.
objpoints = [] # 3d point in real world space
imgpoints = [] # 2d points in image plane.
images = glob.glob('*.jpg')
for fname in images:
    print(fname,'1')
    gray = cv2.imread(fname,0)
    # gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    # Find the chess board corners
    ret, corners = cv2.findChessboardCorners(gray, (cbcol, cbrow),None)
    # If found, add object points, image points (after refining them)
    if ret == True:
        print(fname,'2')
        objpoints.append(objp)
        corners2=cv2.cornerSubPix(gray,corners,(11,11),(-1,-1),criteria)
        imgpoints.append(corners)

        # Draw and display the corners
        cv2.drawChessboardCorners(gray, (cbcol, cbrow), corners2,ret)
        #h=cv2.findHomography(objp,corners2)
        #print(fname,h[0])
        cv2.imshow(fname,gray)
        cv2.waitKey(100)
ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(objpoints, imgpoints, (1292, 964), None, None)
print(ret,'\n', mtx ,'\n', dist,'\n', rvecs,'\n', tvecs)
