#include <stdio.h>
void judge(int month,int day);

main()
{
	int month,day;
	printf("Month:");
	scanf("%d",&month);
	printf("Day:");
	scanf("%d",&day);
	judge(month,day);
}
void judge(month,day){
	switch(month){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day==31){
				printf("This is the last day\n");
			}
			else{
				printf("This is not the last day\n");
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day==30){
				printf("This is the last day\n");
			}
			else{
				printf("This is not the last day\n");
			}
			break;
		case 2:
			if (day==28){
				printf("This is the last day\n");
			}
			else{
				printf("This is not the last day\n");
			}
			break;
	}
}

