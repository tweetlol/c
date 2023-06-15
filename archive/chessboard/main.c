#include<stdio.h>
#include<stdlib.h>

int print_line(int start,int chars){
	int j = 0;
	
	while(j < chars){
		switch(start){
			case 0:
				printf("#");
				break;
			case 1:
				printf(" ");
				break;
		}
	start = (start + 1) % 2;
	j++;
	}

	return(0);
}

int main(){
	int i = 0;
	int j = 0;
	int chars;
	int start = 0;

	printf("obligatory hello world,\nhow many lines should i print? ");
	scanf("%i",&chars);
	printf("\n\n");

	while(i < chars){
		print_line(start,chars);
		printf("\n");
		i++;
		start = (start + 1) % 2;
	}


	return(0);
}
