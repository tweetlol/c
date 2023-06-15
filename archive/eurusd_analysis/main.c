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
	if(c == EOF || c == '!'){
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

void taginputendlines(FILE *f){
	fseek(f,-26,SEEK_END);
	fputc('!',f);
	rewind(f);
}

int main(){
	
	FILE *f_input;
	FILE *f_open;
	FILE *f_high;
	FILE *f_low;
	FILE *f_close;

	int i = 0;
	int ii = 0;

	f_input = fopen("input.txt","r+");
	f_open = fopen("output_open.txt","w+");
	f_high = fopen("output_high.txt","w+");
	f_low = fopen("output_low.txt","w+");
	f_close = fopen("output_close.txt","w+");
	
	taginputendlines(f_input);
	skiplines(f_input,15);

	while(ii < 1){
		ii = nextcharcheck(f_input);
		switch(ii){
			case 0:
				fseek(f_input,41,SEEK_CUR);	//41 for opens
				readandwrite(7,f_input,f_open);
				fputc('\n',f_open);

				fseek(f_input,9,SEEK_CUR);
				readandwrite(7,f_input,f_high);
				fputc('\n',f_high);

				fseek(f_input,9,SEEK_CUR);
				readandwrite(7,f_input,f_low);
				fputc('\n',f_low);

				fseek(f_input,9,SEEK_CUR);
				readandwrite(7,f_input,f_close);
				fputc('\n',f_close);

				nextline(f_input);
				break;
			case 1:
				break;
		}
	}

	fclose(f_input);
	fclose(f_open);
	return(ii);
}



















