#include <stdio.h>

main()
{
	int rank;
	printf("Input rank\n");
	scanf("%d",&rank);
	switch(rank){
		case 1:
			printf("-1st LCD Television\n");
			break;
		case 2:
			printf("-2nd Bicycle\n");
			break;
		case 3:
			printf("-3rd Dinner coupon\n");
			break;
		default:
			printf("-Sorry\n");
			break;
	}
}


