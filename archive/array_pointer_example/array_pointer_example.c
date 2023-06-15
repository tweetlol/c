#include<stdlib.h>
#include<stdio.h>



int main(){
	int* pointer; //pointer to the start of dynamic memory
	pointer = malloc(10 * sizeof(int));
	pointer[0] = 1;
	pointer[1] = 2;
	printf("...\nallocated memory starts at: %p\n",pointer);
	printf("value of: %i\nat pointer: %p\n",pointer[0],&pointer[0]);
	printf("value of: %i\nat pointer: %p\n",pointer[1],&pointer[1]);
	return(0);
}
