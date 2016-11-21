#include <stdio.h>
#include <string.h>
main()
{
	int i,n,frg;
	frg=0;
	printf("Input number\n");
	scanf("%d",&n);
	if (n>=2){
		for (i=2;i<=n-1;i++){
			if (n%i==0){
				frg=1;
				break;
			}
			else{
				frg=0;
			}
		}
	}
	else{
		frg=1;
	}
	if (frg==0){
		printf("素数\n");
	}
	else{
		printf("素数でない\n");
	}
}


