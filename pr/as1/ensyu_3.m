load carsmall

%Cylindersをカテゴリカル変数、Model_Year、MPGを連続値として扱う
t=classregtree([Cylinders Model_Year MPG],Origin,'Categorical',1,'Names',{'Cylinders','Model_Year','MPG'})
tmp=view(t)
set(tmp,'PaperUnits','centimeters')
set(tmp,'PaperPosition',[0 0 33 18])
saveas(tmp,'ensyu_3.jpg')
