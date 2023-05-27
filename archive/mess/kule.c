#include <time.h>
#include <stdio.h>
#include <stdlib.h>


char mem[14][24];	//pole na kulu 14x24 řádky x sloupce (indexy odpovídají)

int memwipe(){	//smaže pole na kulu (nastaví ho na mezerníky - chary)
	int i=0;
	int j=0;
	while(i<14){
		while(j<24){
//			printf("wiping mem[%i][%i]",i,j);
			mem[i][j]=' ';	//mezerník v uvozovkách
			j++;
		}
		j=0;
		i++;
	}
	i=0;
	return(i);
}

int nextline(int i){	//pošle minulou obrazovku do pageup
	int j=0;
	while(j<i){
		printf("\n");
		j++;
	}
	return(i);
}

int setuparena(){	//nastaví okraj pole na kulu na # - chary
	int i=0;
	int j=0;
	while(i<14){
		mem[i][0]='#';
		mem[i][23]='#';
		i++;
	}
	while(j<24){
		mem[0][j]='#';
		mem[13][j]='#';
		j++;
	}
	return(0);
}

int memprint(){	//printne celé pole na kule (včetně areny a kuly)
	int i=0;
	int j=0;
	while(i<14){
		while(j<24){
			printf("%c",mem[i][j]);
			j++;
		}
		printf("\n");
		j=0;
		i++;
	}
	i=0;
	return(i);
}

typedef struct{	//datová struktura má složky {r.x, r.y} jako každý správný polohový vektor
	int x;
	int y;
}COOR;//dinates kule

typedef struct{ //další dat.struk. - rychlost, má složky {v.x, v.y}
	int x;
	int y;
}VELO;//city kule

COOR r={.x=6,.y=6};
VELO v={.x=1,.y=1};


int dt(){
	r.x = r.x + v.x; //dx = v * dt
	r.y = r.y + v.y;
	return(0);
}

int dv(COOR r){
	if(r.x==1 || r.x==12){
		v.x=-(v.x);
	}
	if(r.y==1 || r.y==22){
		v.y=-(v.y);
	}
}

int main(){
	int k=0;
	memwipe();
	setuparena();
	while(k<255){
		nextline(12);	//pošle poslední output do pageup o 12 řádků 
		mem[r.x][r.y]='o';
		memprint();
		mem[r.x][r.y]=' ';
		dv(r);
		dt(r,v);
		
		sleep(1);	//opět hledám kratší sleep - i na tento si gcc stěžuje
		k++;
	}
	return(k);
}















