#include<stdio.h>
#include<limits.h>

int main(){
	printf("#########################\n");
	printf("sizeof unární operátor, definované hodnoty knihovnou limits.h:\n\n");
	
	printf("	CHAR_BIT: %d\n",CHAR_BIT);

	printf("\nsigned char:\n");
	printf("	sizeof(char) = %i\n",sizeof(char));
	printf("	SCHAR_MIN: %d\n",SCHAR_MIN);
	printf("	SCHAR_MAX: %d\n",SCHAR_MAX);

	printf("\nunsigned char:\n");
	printf("	sizeof(unsigned char) = %i\n",sizeof(unsigned char));
	printf("	UCHAR_MIN je nula, lol\n");
	printf("	UCHAR_MAX: %d\n",UCHAR_MAX);

	printf("\nint:\n");
	printf("	sizeof(int) = %i\n",sizeof(int));
	printf("	INT_MIN: %d\n",INT_MIN);
	printf("	INT_MAX: %d\n",INT_MAX);

	printf("\nlong:\n");
	printf("	sizeof(long) = %i\n",sizeof(long));
	printf("	LONG_MIN: %ld\n",LONG_MIN);
	printf("	LONG_MAX: %ld\n",LONG_MAX);



	return(0);
}
