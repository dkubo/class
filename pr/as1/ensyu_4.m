load carsmall

%Weightを1000で割り、小数点以下を切り捨て、千の位で統一する
newWeight=fix(Weight/1000)*1000
%Cylinders、newWeightをカテゴリカル変数、Model_Year、MPGを連続値として扱う
t=classregtree([Cylinders Model_Year MPG newWeight],Origin,'Categorical',[1 4],'Names',{'Cylinders','Model_Year','MPG','Weight'})
tmp=view(t)
set(tmp,'PaperUnits','centimeters')
set(tmp,'PaperPosition',[0 0 33 18])
saveas(tmp,'ensyu_4.jpg')
