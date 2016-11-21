#include <stdio.h>
int judgePass(int input,int pass);		

/*パスワード番号：4649*/
main()
{
	int i,res,input,pass=4649;
	for (i=1;i<=3;i++){
		printf("Input the password number(%d/3):",i);
		scanf("%d",&input);
		res=judgePass(input,pass);	
		if (res==1){
			break;
		}
	}
	if (res==0){
		printf("Your account is not available.\n");
	}
}
int judgePass(int input,int pass){
	int res;
	if (input==pass){
		printf("Success!!\n");
		res=1;
	}
	else{
		res=0;
		printf("You input the wrong number\n");
	}
	return res;
}

