#-*- coding:utf-8 -*-

using DataFrames
using Word2Vec

# coreデータを学習用とテスト用に分割
# 第二引数はclass-a1のIDを列挙したファイル
function split_core_data(source, idf)
  core = open(source, "r")
  class_a1 = readtable(idf, separator = '\t', header = false)[1]
  train, test = open("train_original.txt", "w"), open("test_original.txt", "w")
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

# word2vec
function make_word2vec(wakati_file, model_file)
  @unix? (unix = true) : (unix = false)
  !unix && println("word2vec-learning is unix only")
  !unix && exit()  
  println(wakati_file, "->", model_file)
  println("learning (/・ω・)/・・・")
  word2vec(wakati_file, model_file, verbose = true, size=100, window=5, min_count=5)
  println("finish!!")
end

# 読み込み
function read_word2vec(model_file)
  println("reading (/・ω・)/・・・")
  return wordvectors(model_file)
end

# 類似語出力
function similar_out(model, word)
  println(join([" --- "word," --- "]))
  println(join(cosine_similar_words(model, word),"\n"))
end

# 語の演算結果出力 ph: 加算, mi: 減算
function analogy_out(model,ph,mi)
  if  length(mi) > 0
    println(" --- ( ",join(ph," + ")," ) - ( ",join(mi," + ")," ) --- ")
  else
    println(" --- ( ",join(ph," + ")," ) --- ")
  end
  println(join(analogy_words(model, ph, mi),"\n"))
end

#split_core_data("core_SUW.txt", "test_code.txt")　
#make_wakati("test_original.txt", "test_wakati.txt")
#make_wakati("train_original.txt", "train_wakati.txt")

# おまけ
#make_word2vec("train_wakati.txt", "word2vec.txt")
#model = read_word2vec("word2vec.txt")

# word2vecは長単位のデータでやったほうがうまくいく
#similar_out(model, "政治")
#similar_out(model, "日本")
#analogy_out(model, ["王","女"], ["男"])
