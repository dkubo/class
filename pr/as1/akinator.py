#coding:utf-8
import pandas as pd
from sklearn import tree
import pydotplus
from graphviz import Digraph
from sklearn.externals.six import StringIO

"""
プロ野球データ(http://npb.jp/bis/players/)を対象に決定木を作成
Date:2016/6/23
Name:Daiki Kubo

"""

#文字列データをダミー変数化
def transDummy(data):
	#Position
	dum_posi=pd.DataFrame(pd.get_dummies(data['Position']))
	dum_posi.columns=['Infielder','Fielder','Pitcher','Catcher']
	data=pd.concat([data,dum_posi],axis=1,join_axes=[data.index])
	#Team
	dum_team=pd.DataFrame(pd.get_dummies(data['Team']))
	dum_team.columns=['Fighters','Swallows','Eagles','Hawks','Giants','Tigers']
	data=pd.concat([data,dum_team],axis=1,join_axes=[data.index])
#	PitchArm
	dum_arm=pd.DataFrame(pd.get_dummies(data['PitchArm']))
	dum_arm.columns=['RightArm','LeftArm']
	data=pd.concat([data,dum_arm],axis=1,join_axes=[data.index])
#	SwingArm
	dum_swing=pd.DataFrame(pd.get_dummies(data['SwingArm']))
	dum_swing.columns=['DoubleSwing','RightSwing','LeftSwing']
	data=pd.concat([data,dum_swing],axis=1,join_axes=[data.index])
	#League
	dum_league=pd.DataFrame(pd.get_dummies(data['League']))
	dum_league.columns=['Se_League','Pa_League']
	data=pd.concat([data,dum_league],axis=1,join_axes=[data.index])	
	return data

print 'importing data ....'
labels=['Number','Name','Position','Birthday','Height','Weight','PitchArm','SwingArm','League','Team']
data=pd.read_table('./training_data.tsv',names=labels)
data=transDummy(data)
x=pd.DataFrame(data,columns=['Height','Weight','Infielder','Fielder','Pitcher','Catcher',
										'Fighters','Swallows','Eagles','Hawks','Giants','Tigers',
										'RightArm','LeftArm','Se_League','Pa_League',
										'DoubleSwing','RightSwing','LeftSwing'])
y=pd.Series(data['Name'])

#決定木の分類器をCARTアルゴリズムで作成
print 'make decision tree ....'
clf=tree.DecisionTreeClassifier()
clf=clf.fit(x,y)
dot_data = StringIO()
tree.export_graphviz(clf, out_file=dot_data,feature_names=x.columns)
graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("akinator_graph.pdf")

#モデルを用いて予測を実行する
print 'evaluate model ....'
predicted = clf.predict(x)
#識別率を確認
result = sum(predicted == y) / len(y)
#result=1となった
print result
