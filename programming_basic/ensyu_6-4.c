#include <stdio.h>
#include <math.h>

double calc(int num1,char c,int num2);

main()
{
	int num1,num2;
	char c;
	int res=0;
	printf("Input:");
	scanf("%d %c %d",&num1,&c,&num2);
	res=calc(num1,c,num2);
	printf("result:%d\n",res);
}
double calc(int num1,char c,int num2){
	int res=0;
	switch(c){
		case '+':
			res=num1+num2;
			break;
		case '-':
			res=num1-num2;		
			break;
		case '*':
			res=num1*num2;
			break;
		case '/':
			res=num1/num2;
			break;
	}
	return res;
}
