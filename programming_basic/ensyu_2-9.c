#include <stdio.h>

main()
{
	char arg;
	printf("Input uppercase letter\n");
	scanf("%c",&arg);
	if ( arg >= 'A' && arg <= 'Z' ) {
		arg = arg + ( 'a' - 'A' );
	}
	printf( "小文字は%c\n", arg );
	
}


