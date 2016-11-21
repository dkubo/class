#include <stdio.h>

/*プロトタイプ宣言*/
void calcMul(int arr1[2][2],int arr2[2][2]);

main(){
	int arr1[2][2]={{4,5},{6,7}};
	int arr2[2][2]={{1,2},{3,4}};
	calcMul(arr1,arr2);
}

void calcMul(int arr1[2][2],int arr2[2][2]){
	int i,j,k,term,ans[2][2];
	for(i=0;i<2;++i){
		for(j=0;j<2;++j){
			ans[i][j] = arr1[i][j] * arr2[i][j];
			// 行列の項を計算
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					term=0;
					for(k=0;k<2;k++){
						term = term + arr1[i][k]*arr2[k][j];
						ans[i][j] = term;
					}
				}
			}
		}
	}
	printf("Ans of Multi:\n");
	for (i=0;i<2;i++){
		printf("%d\t",ans[i][0]);
		printf("%d\n",ans[i][1]);
	}
}







