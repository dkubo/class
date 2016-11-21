#include <stdio.h>
#include <string.h>

/*プロトタイプ宣言*/
int	abs_i(int num1);

main(){
/*	int num1,res;*/
	int num1;
	printf("Input a number:\n");
	scanf("%d",&num1);
	num1=abs_i(num1);
	printf("Absolute value:%d\n",num1);

}
int	abs_i(int num1){
	if (num1<0){
		num1=num1*(-1);
	}
	return num1;
}
