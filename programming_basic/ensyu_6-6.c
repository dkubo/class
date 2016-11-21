#include <stdio.h>
int combination(int n,int r);
int calcKaijo(int num);

main(){
	int res=0,n,r;
	printf("Input n:");
	scanf("%d",&n);
	printf("Input r:");
	scanf("%d",&r);
	res=combination(n,r);
	printf("%d\n",res);
}
int combination(int n,int r){
	int i,res=0;
	res=calcKaijo(n)/(calcKaijo(n-r)*calcKaijo(r));
	return res;
}
int calcKaijo(int num){
	int kaijo=1;
	while(num>=1){
		kaijo=kaijo*num;
		--num;
	}
	return kaijo;
}
