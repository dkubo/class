#include <stdio.h>

/*プロトタイプ宣言*/
void calcAdd(int arr1[2][2],int arr2[2][2]);
void calcMinus(int arr1[2][2],int arr2[2][2]);

main(){
	int arr1[2][2]={{4,5},{6,7}};
	int arr2[2][2]={{1,2},{3,4}};
	calcAdd(arr1,arr2);
	calcMinus(arr1,arr2);
}

void calcAdd(int arr1[2][2],int arr2[2][2]){
	int i,j;
	int ans[2][2];
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			ans[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	printf("Ans of Add:\n");
	for (i=0;i<2;i++){
		printf("%d\t",ans[i][0]);
		printf("%d\n",ans[i][1]);
	}
}
void calcMinus(int arr1[2][2],int arr2[2][2]){
	int i,j,ans[2][2];
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			ans[i][j]=arr1[i][j]-arr2[i][j];
		}
	}
	printf("Ans of Minus:\n");
	for (i=0;i<2;i++){
		printf("%d\t",ans[i][0]);
		printf("%d\n",ans[i][1]);
	}
}

