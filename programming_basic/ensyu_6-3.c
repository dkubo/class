#include <stdio.h>
void output(int arr[],int n);

main()
{
	int i,n,num;
	printf("Input N?");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		scanf("%d",&num);
		arr[i]=num;
	}
	output(arr,n);
}
void output(int arr[],int n){
	int i,j,cnt;
	for(i=0;i<n;i++){
		cnt=arr[i];
		printf("%d:",cnt);
		for(j=0;j<cnt;j++){
			printf("*");
		}
		printf("\n");
	}
}
