import pandas as pd
import numpy as np
from matplotlib import*
import random
df=pd.DataFrame(random.randint(3,8),index=['a','b','c','d','e','f','g','h'],columns=['one','two','three'])
print(df)
print(df['one'].median())
print(df['one'].isnull())
#to colculate total number of nul value
print(df.isnull().sum())
#any missing values?
print(df['one'].isnull().values.any())
df.drop(['b'])
df.drop_duplicates()
print(df)

x=[1,2.3,4]
men=[4,3,8,5]
women=[2,5,9,10]
labels=['athletics','aquetics','hockey','tennis']
p1=plt.bar(x,men)
p2=plt.bar(x,women,bottom=men)
plt.xticks(x,labels)
plt.legend(p1[0],p2[0],('Men','women'))
plt.show()
