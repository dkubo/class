#include <stdio.h>
/*二等辺*/
void judgeIsosceles(int len1,int len2,int len3);		
/*正三角*/
void judgeEquilateral(int len1,int len2,int len3);
void judgeTriangle(int len1,int len2,int len3);

main()
{
	int len1,len2,len3;
	printf("Input the length of the three sides:");
	scanf("%d",&len1);
	printf("Input the length of the three sides:");
	scanf("%d",&len2);
	printf("Input the length of the three sides:");
	scanf("%d",&len3);
	judgeTriangle(len1,len2,len3);
}
void judgeTriangle(int len1,int len2,int len3){
	if (len1+len2>len3 && len2+len3>len1 && len3+len1>len2){
		judgeEquilateral(len1,len2,len3);
	}
	else{
		printf("This is not triangle!\n");
	}
}
void judgeEquilateral(int len1,int len2,int len3){
	if ((len1==len2 && len2==len3 && len3==len1)){
		printf("This is Equilateral triangle!\n");
	}
	else{
		judgeIsosceles(len1,len2,len3);		
	}
}void judgeIsosceles(int len1,int len2,int len3){
	if (len1==len2 || len2==len3 || len3==len1){
		printf("This is Isosceles triangle!\n");
	}
	else{
		printf("This is Scalene triangle!\n");
	}
}
