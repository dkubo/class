#coding:utf-8

FILE="../data/core_SUW.txt"

"""
BCCWJ_coreから、行ごとの分かち書きを出力する
作成日：2016/5/31
作成者：久保大輝

"""
FILE="../data/core_SUW.txt"

#registerHash={'OC':'Yahoo!知恵袋'}


def main():
	f=open(FILE,encoding='utf-8')
	for line in f:
#		print(line.split('\t'))
		regiID=line.split('\t')[0]
		sampleID=line.split('\t')[1]
		beginLabel=line.split('\t')[9]
		lemma=line.split('\t')[12]
		subLemma=line.split('\t')[14]
		wType=line.split('\t')[15]
		pos=line.split('\t')[16]
		orthBase=line.split('\t')[21]
		originalText=line.split('\t')[22]

#		print(lemma+","+wType)
		for char in lemma:
			wType=checkType(char)	#1文字ずつに分割して文字種判別
	f.close()

if __name__=='__main__':
	main()


