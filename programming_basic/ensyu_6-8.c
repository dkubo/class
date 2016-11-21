#include <stdio.h>
#include <math.h>

main(){
	int a=1,b=1,c=1;
	double buff1=0.0,buff2=0.0;
	for (b=1;b<=1000;b++){
		for (c=1;c<=1000;c++){
			buff2=b*b+c*c;
			buff1=sqrt((double)buff2);
			a=buff1;
			if(buff1-a==0 && a<=1000){
				printf("%d,%d,%d\n",a,b,c);
			}
		}
	}
}
