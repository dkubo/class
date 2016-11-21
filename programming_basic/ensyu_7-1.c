#include <stdio.h>
main(){
	int *pointer;
	int value;

	printf("Input number:");
	scanf("%4d",&value);
	printf("The input variable:%4d\n",value);
	printf("Address of the input variable:%x\n",&value);

/*valueの値が入っているアドレスをpointerに代入*/
	pointer=&value;
	printf("Input number:");
	scanf("%4d", pointer);
	printf("(pointer): %4d\n",*pointer);
	printf("(value): %4d\n",value);
}
