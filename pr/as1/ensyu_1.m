load carsmall

%Cylindersカテゴリカル変数、Model_Yearを連続値として扱う
t=classregtree([Cylinders Model_Year],Origin,'Categorical',1,'Names',{'Cylinders','Model_Year'})
tmp=view(t)
set(tmp,'PaperUnits','centimeters')
set(tmp,'PaperPosition',[0 0 31 16])
saveas(tmp,'ensyu_1.jpg')

