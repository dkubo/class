#	include	<stdio.h>
# include<math.h>

int calc(int num1,int num2);

main(){
	int num1,num2,res=0;
	printf("Input 2 numbers:\n");
	scanf("%d %d",&num1,&num2);
	res=calc(num1,num2);
	printf("%d\n",res);
}

int calc(int num1,int num2){
	int big=0,small=0,buff=0;
/*	1.入力をa,b(a>=b)とする*/
	if (num1>=num2){
		big=num1;
		small=num2;
	}
	else{
		big=num2;
		small=num1;		
	}
	/*	2.b=0なら、aが最大公約数である*/
	if (small!=0){
		do{
		/*	3.aをbで割った余りを新たにbとし、更にもとのbをaとし手順2に戻る*/
			buff=small;
			small=big%small;
			big=buff;
		}	while (small!=0);
	}
	return big;
}
