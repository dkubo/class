#include <stdio.h>
void sort(int *x,int *y,int *z);

main(){
	int num1,num2,num3;
	printf("Input 3 number:");
	scanf("%d %d %d",&num1,&num2,&num3);
	printf("number1:%d\n",num1);
	printf("number2:%d\n",num2);
	printf("number3:%d\n",num3);
	sort(&num1,&num2,&num3);
	printf("number1:%d\n",num1);
	printf("number2:%d\n",num2);
	printf("number3:%d\n",num3);
}

void sort(int *x,int *y,int *z){
	int i,j,tmp1,tmp2,tmp3,buff;
	int arr[3];
	tmp1=*x;
	tmp2=*y;
	tmp3=*z;
	arr[0]=tmp1;
	arr[1]=tmp2;
	arr[2]=tmp3;
	/*	ソート*/
	for(i=0;i<2;i++) {
		for(j=2;j>i;j--) {
			if(arr[j-1]>arr[j]){
				buff=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=buff;
			}
		}	
	}
/*	printf("number1:%d\n",arr[0]);*/
/*	printf("number2:%d\n",arr[1]);*/
/*	printf("number3:%d\n",arr[2]);*/

  *x=arr[0];
	*y=arr[1];
	*z=arr[2];
}

