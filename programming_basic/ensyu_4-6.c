#	include	<stdio.h>
# include<math.h>

double calcSin(double ang);
double calcCos(double ang);
double calcTan(double ang);

main(){
	double sinValue,cosValue,tanValue,ang;
	printf("Input angle from -180 to 180:\n");
	scanf("%lf",&ang);
	sinValue=calcSin(ang);	
	cosValue=calcCos(ang);	
	tanValue=calcTan(ang);	
	printf("sin：%lf\n",sinValue);
	printf("cos：%lf\n",cosValue);
	printf("tan：%lf\n",tanValue);
}

double calcSin(double ang){
	double sinValue,cosValue,tanValue,rad=0.0;
	rad=M_PI*(ang/180.0);
	sinValue = sin(rad);
	return sinValue;
}
double calcCos(double ang){
	double sinValue,cosValue,tanValue,rad=0.0;
	rad=M_PI*(ang/180.0);
	cosValue = cos(rad);
	return cosValue;
}
double calcTan(double ang){
	double sinValue,cosValue,tanValue,rad=0.0;
	rad=M_PI*(ang/180.0);
	tanValue = tan(rad);
	return tanValue;
}
