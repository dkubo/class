#include <stdio.h>

/*プロトタイプ宣言*/
int	sumArray(int a[],int n);

main(){
	int a[]={34,78,94,35,67,89,54,32,57,47};
	int n=10;
	int sum,ave;
	sum=sumArray(a,n);
	ave=sum/n;
	printf("%d\n",ave);
}

int	sumArray(int a[],int n){
	int i,sum=0;
	for (i=0;i<n;i++){
		sum+=a[i];
	}
	return sum;
}
