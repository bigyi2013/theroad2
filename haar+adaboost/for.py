import  numpy as np
class Haar(object):
    def __init__(self):
        self.dict={}
        self.vec=[]

a=Haar()
a.vec.append(131)
a.vec.append(13)
a.vec.append(11)
a.vec.append(1)
print(np.min(a.vec))