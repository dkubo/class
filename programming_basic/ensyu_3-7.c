#include <stdio.h>
main()
{
	int num1,num2,i;
	num2=500;
	num1=300;
	for (i=1;num2>=num1;num2--){
		if(num2%2==0){
			printf("%d \t",num2);
		}
		else{
			continue;
		}
		if(i%5==0){
			printf("\n");
		}
		i++;
	}
}


