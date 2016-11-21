#include <stdio.h>
void swap(int *x,int *y);

main(){
	int num1,num2;
	printf("Input 2 number:");
	scanf("%d %d",&num1,&num2);
	printf("number1:%d\n",num1);
	printf("number2:%d\n",num2);
	swap(&num1,&num2);
	printf("number1:%d\n",num1);
	printf("number2:%d\n",num2);
}

void swap(int *x,int *y){
	int tmp1,tmp2;
	tmp1=*x;
	tmp2=*y;
	*x=tmp2;
	*y=tmp1;
}

