#include <stdio.h>
int calcEach(int a_n,int n);
int calcTotal(int arr[10]);

main(){
	int a_n=3,total,i,res,n,ans[10];
	ans[0]=a_n;
	for(n=1;n<10;n++){
		res=calcEach(a_n,n);
		a_n=res;
		ans[n]=a_n;
	}
	for(i=0;i<10;i++){
		printf("%d\n",ans[i]);
	}

	total=calcTotal(ans);
	printf("Total:%d\n",total);
}

int calcEach(int a_n,int n){
	int k,a_n1,buff=1;
  for(k=1;k<=n-1;k++){
		buff=buff*2;
  }
	a_n1=a_n+buff;
	return a_n1;
}

int calcTotal(int arr[10]){
	int i,total=0;
	for(i=0;i<10;i++){
		total+=arr[i];
	}
	return total;
}

