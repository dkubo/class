#include <stdio.h>

main(){
	char sen[21];
	char *sen_p;
	int i,zero=0,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0;
	printf("Input number sequent:");
	scanf("%s",sen);
	sen_p=sen;
	for(i=0;sen[i]!='\0';++i){
/*		printf("%c\n",*(sen_p+i));*/
		switch(*(sen_p+i)){
			case '0':
				zero+=1;
				break;
			case '1':
				one+=1;
				break;
			case '2':
				two+=1;
				break;
			case '3':
				three+=1;
				break;
			case '4':
				four+=1;
				break;
			case '5':
				five+=1;
				break;
			case '6':
				six+=1;
				break;
			case '7':
				seven+=1;
				break;
			case '8':
				eight+=1;
				break;
			case '9':
				nine+=1;
				break;
		}
	}
	printf("0:%d回,1:%d回,2:%d回,3:%d回,4:%d回,5:%d回,6:%d回,7:%d回,8:%d回,9:%d回\n",zero,one,two,three,four,five,six,seven,eight,nine);
}
