#include <stdio.h>
#include <string.h>

/*プロトタイプ宣言*/
void letter(char str1,char str2);

main(){
	char str1,str2;
	printf("Input 2 letters:\n");
	scanf("%c%c",&str1,&str2);
	letter(str1,str2);
}
void letter(char str1,char str2){
	if (str1==str2){
		printf("These letters are same.\n");
	}
	else{
		printf("These letters are different.\n");		
	}
}
