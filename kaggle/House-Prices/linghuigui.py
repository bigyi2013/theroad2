import re
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import warnings
def linghuigui(x,y,lam):
    xtx=x.T.dot(x)
    print (xtx.size())
if __name__ == '__main__':
    train_data = pd.read_csv('train.csv')
    test_data = pd.read_csv('test.csv')
    sns.set_style('whitegrid')
    combine=train_data.append(test_data)
    combine=combine[['TotalBsmtSF','1stFlrSF','LotShape','OverallQual','GrLivArea','GarageCars','GarageArea','SalePrice' ]]
    combine['shape']=pd.factorize(combine['LotShape'])[0]
    shape_df=pd.get_dummies(combine['shape'],prefix='shape')
    combine=pd.concat([combine,shape_df],axis=1)
    combine.drop(['shape'],axis=1,inplace=True)
    combine.drop(['LotShape'],axis=1,inplace=True)
    combine['TotalBsmtSF'].fillna(combine['TotalBsmtSF'].mode().iloc[0],inplace=True)
    combine['GarageCars'].fillna(combine['GarageCars'].mode().iloc[0],inplace=True)
    combine['GarageArea'].fillna(combine['GarageArea'].mode().iloc[0],inplace=True)
    train=combine[:1460]
    test=combine[1460:]
    train_data_X=train.drop(['SalePrice'],axis=1)
    train_data_Y=train['SalePrice']
    test_data_X=test.drop(['SalePrice'],axis=1)
    linghuigui(train_data_X.values,train_data_Y.values,0.1)
