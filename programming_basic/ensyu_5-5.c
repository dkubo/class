#include <stdio.h>

/*プロトタイプ宣言*/
void calcAve(int student[4][3]);

main(){
	int student[4][3]={{47,53,61},
								{58,42,40},
								{30,56,52},
								{24,34,40}};
	calcAve(student);
}

void calcAve(int student[4][3]){
	int i,jap=0,math=0,eng=0,jap_ave=0,math_ave=0,eng_ave=0,sum=0,ave=0;
	for (i=0;i<4;i++){
		jap+=student[i][0];
		math+=student[i][1];
		eng+=student[i][2];
	}
	jap_ave=jap/4;
	math_ave=math/4;
	eng_ave=eng/4;
	printf("Average Jap:%d,Math:%d,Eng:%d\n",jap_ave,math_ave,eng_ave);
}

