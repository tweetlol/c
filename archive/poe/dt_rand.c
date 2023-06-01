#include<windows.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int dt;
	while(1){
		n = rand();
		dt = n%50;
		printf("%i ",dt);
		Sleep(100+dt);
	}
	return(0);
}

void rest(){
	int dt;
	dt = rand()%10;
	Sleep(dt);
}
