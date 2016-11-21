#include <stdio.h>


main(){
	int i,max,num[]={43,56,32,98,32,14,76,34,83,41};
	max=num[0];
	for(i=1;i<10;i++){
		if (num[i]>max){
			max=num[i];
		}
	}
	printf("Max Value:%d\n",max);
}


