import numpy as np


def homography(cornerslist, objlist):
    i = 0
    for x in cornerslist:
        list=np.array([[x[0],x[1],1,0,0,0,-objlist[i][0]*x[0],-objlist[i][0]*x[1],-objlist[i][0]],[0,0,0,x[0],x[1],1,-objlist[i][1]*x[0],-objlist[i][1]*x[1],-objlist[i][1]]])
        u=np.array([[objlist[i][0]],[objlist[i][1]]])
        list1=np.array([[x[0],x[1],1,0,0,0,-objlist[i][0]*x[0],-objlist[i][0]*x[1]],[0,0,0,x[0],x[1],1,-objlist[i][1]*x[0],-objlist[i][1]*x[1]]])
        if i==0:
            LIST=list
            LIST1 = list1
            U=u
        else:
            LIST = np.vstack((LIST, list))
            LIST1 = np.vstack((LIST1, list1))
            U=np.vstack((U,u))
        i += 1

    k=np.dot(np.dot(np.linalg.inv(np.dot(LIST1.T,LIST1)),LIST1.T),U)
    # t=np.dot(LIST.T,LIST)
    # eig=np.linalg.eigh(t)
    svd=np.linalg.svd(LIST)
    b=svd[2][8]
    return b
