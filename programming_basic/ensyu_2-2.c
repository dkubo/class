#include <stdio.h>

main()
{
	double num,conv_cm,conv_inch;
	printf("Input number\n");
	scanf("%lf",&num);
	conv_inch = num/2.54;
	conv_cm = num*2.54;
	printf("%f cm = %f inch\n",num,conv_inch);
	printf("%f inch = %f cm\n",num,conv_cm);
}


