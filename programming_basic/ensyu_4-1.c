#include <stdio.h>
#include <string.h>

/*プロトタイプ宣言*/
double	inequality(double,double);

main(){
	double num1,num2,big,small;
	printf("Input 2 real numbers:\n");
	scanf("%lf %lf",&num1,&num2);
	big=inequality(num1,num2);
	if (num1==big){
		printf("High number is %lf.\n",big);
		printf("Low number is %lf.\n",num2);
	}
	else if(num2==big){
		printf("High number is %lf.\n",big);
		printf("Low number is %lf.\n",num1);
	}
	else{
		printf("These numbers are same.\n");
	}
}

double inequality(double num1,double num2){
	double big;
	if (num1>num2){
		big=num1;
	}
	else if (num1<num2){
		big=num2;
	}
	else{
		return 0;
	}
	return big;
}
