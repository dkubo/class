#include <stdio.h>
#include <math.h>

main()
{
	int i,j,n,g,num1,num2;
	double totalPerson=0.0,totalMath=0.0,totalEng=0.0,avePerson=0.0,aveMath=0.0,aveEng=0.0,totalave=0.0,aveOfave=0.0;
	printf("How many students? ");
	scanf("%d",&n);
	double arr[n+1][3];
	for(i=0;i<n;i++){
		printf("Student %d:",i+1);
		scanf("%d %d",&num1,&num2);
		arr[i][0]=num1;
		arr[i][1]=num2;
		arr[i][2]=0.0;
	}
/*計算*/
	for(i=0;i<n;i++){
		totalMath+=(double)arr[i][0];
		totalEng+=(double)arr[i][1];
		totalPerson=0.0;
		avePerson=0.0;
		for(j=0;j<2;j++){
			totalPerson+=(double)arr[i][j];
		}
		avePerson=totalPerson/2.0;
		arr[i][2]=avePerson;
		totalave+=avePerson;
	}
	aveMath=totalMath/(double)n;
	aveEng=totalEng/(double)n;
	aveOfave=totalave/(double)n;
	arr[n][0]=aveMath;
	arr[n][1]=aveEng;
	arr[n][2]=aveOfave;
	
/*	出力*/
	printf("ID\tMath\t\tEnglish\t\tAverage\n");
	for(i=0;i<n;i++){
		printf("%d.\t%lf\t%lf\t%lf\n",i+1,arr[i][0],arr[i][1],arr[i][2]);
	}
	printf("Average\t%lf\t%lf\t%lf\n",arr[i][0],arr[i][1],arr[i][2]);			
}
