#include <stdio.h>
main(){
	int a;
	float b;
	double c;
	char d;
	
	int *pa;
	float *pb;
	double *pc;
	char *pd;
	
	pa=&a;
	pb=&b;
	pc=&c;
	pd=&d;
	
	printf("%x\n",pa);
	printf("%x\n",pb);
	printf("%x\n",pc);
	printf("%x\n",pd);
	
	printf("%x\n",pa+1);
	printf("%x\n",pb+1);
	printf("%x\n",pc+1);
	printf("%x\n",pd+1);
	
}

