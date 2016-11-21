#include <stdio.h>
main()
{
	int num1,num2,sum;
	num2=500;
	num1=300;
	for (;num2>=num1;num2--){
		if(num2%2==0){
			printf("%d \t",num2);
		}
		else{
			continue;
		}
	}
}


