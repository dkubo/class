#include <stdio.h>
#include <string.h>
main()
{
	int i,n,num;
	double sum,ave;
	sum=0.0;
	ave=0.0;
	printf("Input number\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++){		
		printf("Input number\n");
		scanf("%d",&num);
		sum+=num;
	}
	ave=sum/n;
	printf("sum:%lf\n",sum);
	printf("ave:%lf\n",ave);
}


