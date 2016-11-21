#include <stdio.h>
#include <string.h>
main()
{
	int i,n,div,digit,res,buff;
	buff=0;
	digit=1;
	div=1;
	res=0;
	printf("Input number\n");
	scanf("%d",&n);
	buff=n;
	while(buff/10!=0){
		digit++;
		buff=buff/10;
	}
/*	printf("%d\n",digit);*/

	for (i=1;i<=digit;i++){
		res=n%(10);
		n=(n-res)/10;
		printf("%d",res);
	}
	printf("\n");
}
