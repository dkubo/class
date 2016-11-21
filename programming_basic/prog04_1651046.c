#include <stdio.h>
int output(int *num);

main()
{
	int arr[10]={67,25,14,43,20,7,92,58,36,83};
	int max;
	max=output(&arr[0]);
	printf("%d\n",max);
}
int output(int *num){
	int i,max=0;
	for(i=0;i<10;i++){
		if(max<*(num+i)){
			max=*(num+i);
/*		printf("%d\n",*(num+i));*/
		}
	}
	return max;
}

