# usage
# R --vanilla --slave  --args < a.R
# data<-read.table("PCATutorial.txt")
# data.m<-colMeans(data[,2:11])
# data.v<-var(data[,2:11])
# data.d<-mahalanobis(data[,2:11],data.m,data.v)
# data.d
# hist(data.d)

# data<-read.table("DataGE1.txt", header=T)
# split_data<-data[,2:4]
# data.d<-dist(t(split_data),method="euclidean")
# data.d
# corm<-cor(split_data)
# corm
# data[,1] <- factor(substring(data[,1], 1, 3))
# data.pca <- prcomp(data[,2:11],center=T,scale.=T)
# data.pca
# summary(data.pca)
# plot(data.pca$x[,1:2],col=as.integer(data[,1]),pch=as.integer(data[,1]))
# par(new=T)
# legend("topright",legend=levels(data[,1]),col=1:10,pch=1:10)