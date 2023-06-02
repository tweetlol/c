#include<stdlib.h>
#include<stdio.h>

void nextline(FILE *f){
	char c;
	while(c != '\n' && c != EOF){
		c = fgetc(f);
	}
}

int nextcharcheck(FILE *f){	//checks for EOF
	char c;
	c = fgetc(f);
	if(c == EOF){
		return(1);
	}else{
		fseek(f,-1,SEEK_CUR);
		return(0);
	}
}

void skiplines(FILE *f,int lines){	//skips c lines
	char c;
	int i = 0;
	while(i < lines){
		while(c != '\n'){
			c = fgetc(f);
		}
		i++;
		c = 0;
	}
}

void readandwrite(int c, FILE *input_file, FILE *output_file){
	int i = 0;
	while(i < c){
		fputc(fgetc(input_file),output_file);
		i++;
	}
}

int main(){
	
	FILE *fi;
	FILE *fo;
	int i = 0;
	int ii = 0;

	fi = fopen("input.txt","r");
	fo = fopen("output.txt","w+");
	
	skiplines(fi,15);

	while(ii < 1){
		ii = nextcharcheck(fi);
		switch(ii){
			case 0:
				fseek(fi,41,SEEK_CUR);	//41 for opens
				readandwrite(7,fi,fo);

				fputc('\n',fo);
				nextline(fi);
				break;
			case 1:
				break;
		}
	}

	fclose(fi);
	fclose(fo);
	return(ii);
}



















