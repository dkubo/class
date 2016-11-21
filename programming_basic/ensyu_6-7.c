#include <stdio.h>
int DayperMonth(int month);

main(){
	int i,month,day,res=0;
	printf("Input month:");
	scanf("%d",&month);
	printf("Input day:");
	scanf("%d",&day);
	for(i=month-1;i>=1;i--){
		res+=DayperMonth(i);
	}
	res+=day;
	printf("%ddays\n",res);
}
int DayperMonth(int month){
	int resDay;
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			resDay=31;
			return resDay;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			resDay=30;
			return resDay;
			break;
		case 2:
			resDay=28;
			return resDay;
			break;
	}
}

