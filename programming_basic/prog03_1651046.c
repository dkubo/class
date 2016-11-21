#include <stdio.h>

main(){
	double arr[2][2];
	double revarr[2][2];
	double revarr_2[2][2];
	int i,j,k;
	double term;
	double a,b,c,d,buf=0.0;
	printf("Input a b c d:");
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	printf("-------------------------\n");
	arr[0][0]=a;
	arr[0][1]=b;
	arr[1][0]=c;
	arr[1][1]=d;
	for(i=0;i<=1;i++){
		printf("%lf %lf\n",arr[i][0],arr[i][1]);
	}
	printf("-------------------------\n");
	buf=a*d-b*c;
	if(buf==0.0){
		printf("逆行列が存在しません.\n");
	}else{
		revarr[0][0]=d/buf;
		revarr[0][1]=(b*-1)/buf;
		revarr[1][0]=(c*-1)/buf;
		revarr[1][1]=a/buf;
		printf("逆行列：\n");
		for(i=0;i<=1;i++){
			printf("%lf %lf\n",revarr[i][0],revarr[i][1]);
		}
	}
  for(i=0;i<2;++i){
    for(j=0;j<3;++j){
      revarr_2[i][j]=revarr[i][j] * revarr[i][j];
      for(i=0;i<2;i++){
        for(j=0;j<3;j++){
          term = 0.0;
          for(k=0;k<2;k++)
            term=term+revarr[i][k]*revarr[k][j];
          revarr_2[i][j]=term;
        }
      } 
    }
  }
	printf("-------------------------\n");
	printf("逆行列の2乗：\n");
	for(i=0;i<=1;i++){
		printf("%lf %lf\n",revarr_2[i][0],revarr_2[i][1]);
	}
}

