import numpy as np
def uv(uv,corners):
    #print(corners)
    #取反然后加1080 正常xy坐标系
    #print(corners[uv - 1][0][0], -(corners[uv - 1][0][1]) + 964)
    #print((corners[uv - 1][0][0])-(corners[9 - 1][0][0]), (-(corners[uv - 1][0][1]) + 964)-(-(corners[9 - 1][0][1]) + 964))
    #return (corners[uv - 1][0][0])-(corners[9 - 1][0][0]),(-(corners[uv - 1][0][1]) + 964)-(-(corners[9 - 1][0][1]) + 964)
    #print(corners[uv - 1][0][0]-646, (-(corners[uv - 1][0][1])+964)-482)
    return corners[uv - 1][0][0], corners[uv - 1][0][1]

    #return corners[uv-1][0][0],corners[uv-1][0][1]
def xy(x,y):
    i=np.linspace( 0, 12*30, 13 )
    j=np.linspace(0,11*30,12)
    #print(i[x - 1], j[y - 1])
    return i[x - 1], j[y - 1]