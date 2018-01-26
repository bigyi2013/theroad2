
from getcorners import  getcorners
from geth import geth
#filename = glob.glob('tupian/*.bmp')
def gethmean(filename):
    corners=getcorners(filename)
    #print(corners)
    sumh=0
    tick=0

    h2, uvrank, xyrank=geth(2,50,123,corners,filename)
    return h2
    #     print(i)
    # return sumh/tick
# filename='l03.bmp'
# h=gethmean(filename)
# print(h)
