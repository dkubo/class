#coding:utf-8
import matplotlib.pyplot as plt
from matplotlib.font_manager import FontProperties
from matplotlib.ticker import *
import matplotlib.ticker as tick
from pylab import *

#2xの場合,2x+hの場合,2x-hの場合やる

def calc(calcType):
	print("--------------------")
	#初期値の設定
	cnt=0
	x = 1.0
	h = 1.0
	carray=[0]
	loss=[1.0]
	value=[1.0]
	
	while True:
		# ニュートン法による新しいxを求める
		if calcType == '2x':
			x2 =  x - (x * x - 5) / (x * 2)
		elif calcType == '2x_plus':
			x2 =  x - (x * x - 5) / (x * 2+h)
		elif calcType == '2x_minus':
			x2 =  x - (x * x - 5) / (x * 2-h)
		l=abs(x2 - x)
		#誤差の絶対値
		# 計算後の値が誤差の範囲内になったら計算終了
		if l < 10**-12:
			break
		# 計算後の値をxとして計算を繰り返す
		x = x2
		cnt+=1
		carray.append(cnt)
		value.append(x2)
		loss.append(l)
	return carray,loss,value

if __name__ == '__main__':
	carray_2x,loss_2x,value_2x = calc('2x')
	carray_2x_plus,loss_2x_plus,value_2x_plus = calc('2x_plus')
	carray_2x_minus,loss_2x_minus,value_2x_minus = calc('2x_minus')
	print(loss_2x_minus)
	#図示
	plt.plot(carray_2x, value_2x,label=u"中央差分")
	plt.plot(carray_2x, value_2x,label=u"前進差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x, value_2x,label=u"中央差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x, value_2x,label=u"後進差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x_plus, value_2x_plus,label=u"前進差分")
	plt.plot(carray_2x_minus, value_2x_minus,label=u"後進差分")

	plt.ylim(0.0, 5.0)
	plt.xlabel("Repeat time")
	plt.ylabel("Value")
	fp = FontProperties(fname='/usr/share/fonts/truetype/takao-gothic/TakaoGothic.ttf',size=10)
	plt.legend(prop=fp,loc='lower right')
	plt.show()

	plt.yticks(arange(0.0,4.0,0.1))
#	plt.gca().xaxis.set_major_locator(tick.MultipleLocator(1))
#	plt.gca().yaxis.set_major_locator(tick.MultipleLocator(100))

	plt.plot(carray_2x, loss_2x,label=u"中央差分")
	plt.plot(carray_2x, loss_2x,label=u"前進差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x, loss_2x,label=u"中央差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x, loss_2x,label=u"後進差分のRichardson補外（Romberg1段）")
	plt.plot(carray_2x_plus, loss_2x_plus,label=u"前進差分")
	plt.plot(carray_2x_minus, loss_2x_minus,label=u"後進差分")

	plt.xlabel("Repeat time")
	plt.ylabel("Absolute value of loss")
	fp = FontProperties(fname='/usr/share/fonts/truetype/takao-gothic/TakaoGothic.ttf',size=10)
	plt.legend(prop=fp,loc='lower right')
	plt.show()

