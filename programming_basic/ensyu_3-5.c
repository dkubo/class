#include <stdio.h>
main()
{
	int num1,num2,sum;
	sum=0;
	printf("Input number1\n");
	scanf("%d",&num1);
	printf("Input number2\n");
	scanf("%d",&num2);
	for (;num1<=num2;num1++){
		sum+=num1;
	}
	printf("%d \n",sum);
}


