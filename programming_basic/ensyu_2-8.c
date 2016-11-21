#include <stdio.h>

main()
{
	int buff;
	double arg,ans;
	printf("Input number\n");
	scanf("%lf",&arg);
	buff=arg;
	ans=arg-buff;
	if (ans>=0.5)
		buff++;
	printf("%d \n",buff);
}


