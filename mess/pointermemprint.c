#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[10];
	int i=0;
	while(i<10){
		a[i]=0;
		printf("(%i) there's %i @ mem adress: %p\n",i,a[i],&a[i]);
		i++;
	}


	return(0);
}
