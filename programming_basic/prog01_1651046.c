#include <stdio.h>

double abs(double num1);

main(){
	double num1,num2;
	printf("Input number:");
	scanf("%lf",&num1);
	printf("元の数値：%lf\n",num1);
	num2=abs(num1);
	printf("絶対値：%lf\n",num2);
}

double abs(double num1){
	double num2;
	num2=num1;
	if(num1<0.0){
		num2=num1*-1.0;
	}
	return num2;
}

