#include <stdio.h>
#include <string.h>
main()
{
	int i,n;
	printf("Input number\n");
	scanf("%d",&n);
	i=1;
	for (i=2;i<=n;i++){
		while(n%i==0){
			printf("%d\t",i);
			n=n/i;
		}
	}
	printf("\n");	
}


