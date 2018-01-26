import pandas as pd
import numpy as np
from  pandas import  Series,DataFrame
import matplotlib.pyplot as plt

s = pd.Series([1,3,5,np.nan,6,8])
#print(s)

dates=pd.date_range('20130101',periods=6)
#print(dates)#.date_range

df=pd.DataFrame(np.random.randn(6,4),index=dates,columns=list('ABCD'))
print(df.mean())
print(df.mean(1))
print(df)