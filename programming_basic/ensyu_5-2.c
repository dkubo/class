#include <stdio.h>

main(){
	int i,pnum,snum,sum=0,average=0;
	printf("Input the number of people:\n");
	scanf("%d",&pnum);
	int array[pnum];
	for (i=0;i<pnum;i++){
		printf("Input the studenr number %d:",i+1);
		scanf("%d",&snum);
		array[i]=snum;
	}

	for (i=0;i<pnum;i++){
		sum+=array[i];
	}
	average=sum/pnum;
	printf("Sum:%d\n",sum);
	printf("Average:%d\n",average);	
}


