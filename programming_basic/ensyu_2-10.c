#include <stdio.h>

main()
{
	int ans,coffee,milk,val;
	coffee=108;
	milk=128;
	
	val=(coffee+2*milk)*1.08;
	ans=1000-val;
	printf("合計金額；%d \n",val);
	printf("お釣り；%d \n",ans);
}


