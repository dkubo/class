#include <stdio.h>
#include <string.h>
main()
{
	int i,n,frg;
	frg=0;
	printf("Input number\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		if (n%i==0){
			printf("%d\t",i);
		}
	}
	printf("\n");	
}


