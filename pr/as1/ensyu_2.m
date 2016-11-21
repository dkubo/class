load carsmall

%Cylinders、MPGをカテゴリカル変数、Model_Yearを連続値として扱う
t=classregtree([Cylinders Model_Year MPG],Origin,'Categorical',[1 3],'Names',{'Cylinders','Model_Year','MPG'})
tmp=view(t)
set(tmp,'PaperUnits','centimeters')
set(tmp,'PaperPosition',[0 0 33 18])
saveas(tmp,'ensyu_2.jpg')
