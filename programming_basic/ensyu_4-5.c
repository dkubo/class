#	include	<stdio.h>
# include<math.h>
/*# define M_PI*/

double calc(double r);

main(){
	double r,res=0.0;
	printf("Input radius:\n");
	scanf("%lf",&r);
	res=calc(r);
	printf("円の面積：%lf\n",res);
}

double calc(double r){
	double res;
	res=r*r*M_PI;
	return res;
}
