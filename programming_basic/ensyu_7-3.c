#include <stdio.h>
main(){
	int i,x[10];
	int *x_p;
	for(i=0;i<10;i++){
		x[i]=i;
	}
	x_p=x;
	for(i=0;i<10;i++){
		printf("%d\n",*x_p+i);
	}
}
