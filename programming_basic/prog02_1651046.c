#include <stdio.h>

void output(int month,int day);
int DayperMonth(int month);

main(){
	int month,day;
	printf("Input Month and Day:");
	scanf("%d %d",&month,&day);
	output(month,day);
}

void output(int month,int day){
	int i,resDay;
	int array[365];
	/*	金曜日:4 */
	int ans=4;
	for(i=month-1;i>=1;i--){
		resDay+=DayperMonth(i);
	}
	resDay+=day;
	for (i=0;i<366;i++){
		array[i]=ans;
		if(ans==6){
			ans=0;
		}else{
			ans+=1;
		}
	}
	switch(array[resDay]){
		case 0:
			printf("Monday!\n");
			break;
		case 1:
			printf("Tuesday!\n");
			break;
		case 2:
			printf("Wednesday!\n");
			break;
		case 3:
			printf("Thursday!\n");
			break;
		case 4:
			printf("Friday!\n");
			break;
		case 5:
			printf("Saturday!\n");
			break;
		case 6:
			printf("Sunday!\n");
			break;
	}
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
			resDay=29;
			return resDay;
			break;
	}
}

