#include <stdio.h>
main(){
	int a=20;
	int b=10;
	int *a_p,*b_p;
	
	a_p=&a;
	b_p=&b;
	printf("和: %4d\n",*a_p+*b_p);
	printf("差: %4d\n",*a_p-*b_p);
}
