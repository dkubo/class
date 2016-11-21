#coding:utf-8

"""
パターン認識_課題2
1651046, Daiki Kubo

Usage:
	python pr2.py

"""
from sklearn.datasets import fetch_mldata
from sklearn.decomposition import PCA
from sklearn.cross_validation import train_test_split
from scipy.spatial import KDTree
import numpy as np
import time
import random

# 高次元データセット(MNIST)取得
def get_dataset():
	mnist = fetch_mldata('MNIST original', data_home="./data/")
	data = mnist["data"]
	target = mnist["target"]
	train, _, _, _ = train_test_split(data, target)
	#( train:52500, test:17500)
	return train		# trainデータを今回の課題のデータセットとする

# 累積寄与率計算
def calc_ratio(data, X, start=25):
	n_comp = 0
	e = 0.0					# 寄与率
	accum_e = 0.0		# 累積寄与率
	for i, n_comp in enumerate(range(start, 100)):
		pca = PCA(n_components = n_comp)  	# 主成分分析オブジェクトの作成
		pca.fit(data)                       # 主成分分析の実行
		e = pca.explained_variance_ratio_		# 寄与率
		accum_e = sum(e)
		if accum_e >= X:
			return n_comp
			break

# サンプル画像を低次元化する
def dim_reduc(data, n_comp):
	pca = PCA(n_components = n_comp)
	pca.fit(data)
	vec_pca = pca.transform(data)		# ベクトル化
	return vec_pca

# テスト画像との最近傍を探索 (ユーグリッド距離)
def search_nearest(vec_space, vec_test):
	nearest_idx = 0			# 最近傍のインデックス
	min_dist = 0.0
	vec_space = np.array(vec_space, dtype=np.float32)			# numpy形式に変換
	vec_test = np.array(vec_test, dtype=np.float32)
#	print vec_pca.shape				# (52500, 43)
#	print vec_test.shape			# (43,)
	start = time.time()				# 計測開始
	for i, vec in enumerate(vec_space):
#		print vec.shape					# (43,)
		dist = np.sqrt(np.power(vec-vec_test, 2).sum())
		if dist < min_dist:
			nearest_idx = i
			max_sim = sim
#	print max_sim		# 1.0
#	print nearest_idx		# index
	calc_time = time.time() - start
	return calc_time

# 低次元化による探索効率化の程度を示す
def evaluate_time(before, after):
	return after/before

# おまけ問題: KD-treeによる探索
def kd_tree(vec_space, vec_test):
	vec_space = np.array(vec_space, dtype=np.float32)			# numpy形式に変換
	vec_test = np.array(vec_test, dtype=np.float32)
	start = time.time()				# 計測開始
	tree = KDTree(vec_space)
	distance, index = tree.query(vec_test, k=1)
	calc_time = time.time() - start
	return calc_time


if __name__ == '__main__':
	before_time = 0.0
	after_time = 0.0
	n_comp = 25
	X_array = [0.7,0.8,0.9]	# X=0.7,0.8,0.9の3通りについて実験を行う
	
	# データセット取得	
	data = get_dataset()

	for X in X_array:
		print "***********************************"
		print "X =", X

	# 累積寄与率を計算
		n_comp = calc_ratio(data, X, n_comp)
		print "圧縮後次元数：", n_comp
		
	# サンプルデータセットを低次元化
		vec_pca = dim_reduc(data, n_comp)
		print "次元圧縮後のベクトル空間：", vec_pca

	# ランダムにテスト画像を１つ選択
		index = random.randint(0,52499)
	# 元の高次元空間における最近傍を探索
		test_sample = data[index]
		before_time = search_nearest(data, test_sample)
		print "圧縮前探索時間：", before_time

	# 次元圧縮空間における最近傍を探索
		test_sample = vec_pca[index]
		after_time = search_nearest(vec_pca, test_sample)
		print "圧縮後探索時間：", after_time

		# 探索時間の評価
		result = evaluate_time(before_time, after_time)	
		print "探索時間の比：", result

		# おまけ問題(KD-treeによる探索)
		print "#####おまけ問題(KD-treeによる探索)#####"
		# 圧縮前
		test_sample = data[index]
		before_time = kd_tree(data, test_sample)
		print "圧縮前探索時間：", before_time
		# 圧縮前
		test_sample = vec_pca[index]
		after_time = kd_tree(vec_pca, test_sample)
		print "圧縮後探索時間：", after_time

		# 探索時間の評価
		result = evaluate_time(before_time, after_time)	
		print "探索時間の比：", result
	
	
	
	
