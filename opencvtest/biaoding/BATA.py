import numpy as np

A=np.array([( 1.21797771e+00  , 3.13019598e-01,  -5.99097586e-02),
            (0.00000000e+00,1.21845370e+00,3.55897814e-01),
 ( 0.00000000e+00 ,  0.00000000e+00  , 1.02796232e+03)])

B=np.array( [[  1.87884498e+03 ,  0.00000000e+00  , 6.38410151e+02],
 [  0.00000000e+00  , 1.78255476e+03  , 2.47990625e+02],
 [  0.00000000e+00 ,  0.00000000e+00   ,1.00000000e+00]] )
print('B:',B)
print('A:',A)
Ani=np.linalg.inv(A)
Bni=np.linalg.inv(B)
print(Bni.T.dot(Bni))
print(Ani.T.dot(Ani))