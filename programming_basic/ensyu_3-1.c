#include <stdio.h>

main()
{
	int num;
	printf("Enter integer\n");
	scanf("%d",&num);
	if (num==0){
		printf("zero\n");
	}
	else if (num>0){
		printf("positive\n");
	}
	else{
		printf("negative\n");
	}
}


