import numpy as np
def xy(m,n):
    i=np.linspace( 0, 12*30, 13 )
    j=np.linspace(0,11*30,12)
    return i[m-1],j[n-1]