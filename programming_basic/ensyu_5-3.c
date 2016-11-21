#include <stdio.h>

int	calcAn_1(int a_n,int d);

main(){
	int i,a1,d,a_n1,sum=0,average=0;
	printf("An = An-1 + d:\n");	
	printf("Input the first term(A1):\n");
	scanf("%d",&a1);
	printf("Input common difference(d):\n");
	scanf("%d",&d);
	printf("A1:%d\n",a1);
	a_n1=calcAn_1(a1,d);
	for (i=2;i<=10;i++){
	printf("A%d:%d\n",i,a_n1);
	a_n1=calcAn_1(a_n1,d);
	}
}

int	calcAn_1(int a_n,int d){
	int a_n1=0;
	a_n1=a_n+d;
	return a_n1;
}

