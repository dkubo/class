#-*- coding:utf-8 -*-

using DataFrames

# coreデータを学習用とテスト用に分割
# 第二引数はclass-a1のIDを列挙したファイル
function split_core_data(source, idf)
  core = open(source, "r")
#  class_a1 = readtable(idf, separator = '\t', header = false)[1]
	fp=open(idf)
	
#	class_a1:IDの配列
  train, test = open("../data/train_original.txt", "w"), open("../data/test_original.txt", "w")
  println("分割中(/・ω・)/・・・")
  for line in eachline(core)
    data = split(line, "\t")
    if data[2] in class_a1
      write(test, line)
    else
      write(train, line)
    end
  end
  close(train)
  close(test)
end

# WordSegmentation用の形式に変換
# めんどくさいので型指定してない
function make_wakati(ifile,ofile)
  f,o = open(ifile, "r"), open(ofile, "w")
  println("行ごとの分かち書きに変換中(/・ω・)/・・・")
  sentence = []
  for line in eachline(f)
    data = split(line, "\t")
    word, head = data[24],data[10]
    if (sentence != [] && head == "B")
      write(o, join(sentence, " ")*"\n")
      sentence = [word]
    else
      push!(sentence, word)
    end
  end
end

split_core_data("../data/core_SUW.txt", "../data/ClassA-1.txt")　
make_wakati("../data/test_original.txt", "../data/test_wakati.txt")
make_wakati("../data/train_original.txt", "../data/train_wakati.txt")
