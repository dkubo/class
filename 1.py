#coding:utf-8

import math


def calc(alpha,var,x,mean):
	res=0.0
	res = alpha*((1./math.sqrt(2.*math.pi*var))*math.exp((-1./2.*var)*(x-mean)**2.))
	return res
	
if __name__ == '__main__':
	xArr=[-6/5.,2/5.,0.,4/5.,6/5.]
	alphaArr=[0.3,0.7]
	meanArr=[6/10.,4/10.]
	varArr=[1.,2.]
	xArr=map(float,xArr)
	meanArr=map(float,meanArr)
	varArrw=map(float,varArr)
	for n in range(0,5):
		for m in range(0,2):
			print "n="+str(n+1)+", m="+str(m+1)
			res=calc(alphaArr[m],varArr[m],xArr[n],meanArr[m])
			print res
