#include <stdio.h>
#include <string.h>

/*プロトタイプ宣言*/
main(){
	char name[10]="Daiki Kubo";
	int i,*pa,frg=0;
	char buff;
	printf("%c.",name[0]);
	for (i=0;i<strlen(name);i++){
/*		空白が来たらフラグ*/
		if (name[i] == ' '){
			frg=1;
		}
		else if(frg==1){
			printf("%c\n",name[i]);
			frg=0;
		}
	}
}
