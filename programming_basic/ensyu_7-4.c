#include <stdio.h>
main(){
	int a=1;
	float b=1.2;
	double c=1.23;
	int *pa;
	float *pb;
	double *pc;
	
	pa=&a;
	pb=&b;
	pc=&c;
	
	printf("%d\n",*pa);
	printf("%lf\n",*pb);
	printf("%lf\n",*pc);
}
