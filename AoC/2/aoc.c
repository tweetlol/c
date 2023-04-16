#include<stdio.h>
#include<stdlib.h>

int main(){

	FILE *fp;
	int score=0;
	fp = fopen("input.txt","r");
	int opp,ja,i=0;
	
	
for(1;;){
	
	i++;
	opp = fgetc(fp);
	fseek(fp,1,SEEK_CUR);
	ja = fgetc(fp);
	
	if(feof(fp)){
		break;
	}
	
	fseek(fp,1,SEEK_CUR);
	printf("ROUND %i, FIGHT: %c vs %c \n",i,opp,ja);
	switch(opp){
		case 65: // on kámen
			switch(ja){
				case 88:
					score=score+4;
				case 89:
					score=score+8;
				case 90:
					score=score+3;
			}
		case 66: //on papír
			switch(ja){
				case 88:
					score=score+1;
				case 89:
					score=score+5;
				case 90:
					score=score+9;
			}
		case 67: //on nùžky
			switch(ja){
				case 88:
					score=score+7;
				case 89:
					score=score+2;
				case 90:
					score=score+6;
			}
	}
}
	printf("TOTAL SCORE: %i",score);

return(0);
}






















