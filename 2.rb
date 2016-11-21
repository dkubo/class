#coding:utf-8

def func(x)
	return 1/(1+x.to_f)
end

n=4
I=0.6931471805599453		#log2
while n<=128 do
	sigma_part=0
	for i in 1..n-1 do
		sigma_part += func(i/n.to_f)
	end
	i_n = (0.5*(func(0)+func(1))+sigma_part)/n
	i_n_I= i_n - I
	n_2_i_n_I = n*n*i_n_I
	n=n*2
	puts n_2_i_n_I
end

