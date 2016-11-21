#coding:utf-8
# 任意の関数 f(x) の [a, b] での積分をモンテカルロ法で求める
import numpy as np
from scipy import stats
from scipy.integrate import quad
import math

a=0.0
b=2.0*np.pi
def f(x):
	return abs(np.sin(x))

# モンテカルロ積分
y=[]
N = 1000
x = stats.uniform(loc=a, scale=b-a).rvs(size=N)
for i in x:
	y.append(f(x))

alpha=0.95
mean_val=np.mean(y)
I=(b-a)*mean_val
var=np.var(y)

print("モンテカルロ積分:",I)
print("分散:",var)

