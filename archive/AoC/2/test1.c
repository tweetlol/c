#include<stdio.h>
#include<stdlib.h>

int main(){

	FILE *fp;
	int score=0;
	fp = fopen("input.txt","r");
	int opp,ja=0;
	
	opp = fgetc(fp);
	fseek(fp,1,SEEK_CUR);
	ja = fgetc(fp);
	fseek(fp,1,SEEK_CUR);
	printf("%c %i     %c %i",opp,opp,ja,ja);
	
	return(0);
}
