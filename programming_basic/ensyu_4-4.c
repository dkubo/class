#	include	<stdio.h>
void sub(void);
int e_var=0;	 		

main(){	
	int i;
	for (i=1;i<=10;i++){
		sub();
		e_var++;
	}
}

void sub(void){
	auto int a_var=0;
	static int s_var=0;
	extern int e_var;
	a_var++;
	s_var++;
	e_var++;
	printf("a_var=%d,s_var=%d,e_var=%d\n",a_var,s_var,e_var);
}
