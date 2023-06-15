#include<stdio.h>
#include<stdlib.h>


void ui_0(int* studs, int* marks){	//jako argumenty žere pointery, jejichž příslušné paměti naplní user inputem
	
		printf("\n----------\nobligatory hello world,\nzadejte počet studentů a známek na studenta (např.: \"12 5\"): ");
		scanf("%i %i",studs,marks);
}

void ui_1(int i, int marks, int* array1){
	
	int j = 0;
	printf("zadejte postupně %i známek studenta #%i (oddělené mezerou): ",marks,i);
	while(j < marks){
		scanf("%i",&array1[marks*i + j]);
		j++;
	}
}

void calculate_averages(int studs, int marks, int* array1, double* array2){

	int i = 0;
	int j = 0;
	while(j<studs){
		while(i<marks){
			array2[j] = array2[j] + array1[marks*j + i];
			i++;
		}
		array2[j] = array2[j] / marks;
		j++;
		i = 0;
	}
}

void print_marks(int i, int marks, int* array1, double* array2){

	int j = 0;
	printf("\nstudent #%i:",i);
	while(j < marks){
		printf(" %i",array1[marks*i + j]);
		j++;
	}
	printf(" | průměr: %.2f",array2[i]);
}

int main(){
	
	int i = 0;
	int studs,marks;
	int* array1;	//na známky
	double* array2;	//na průměry
	
	ui_0(&studs,&marks);
	
	printf("\npočet studentů: %i, známek na studenta: %i\n",studs,marks);
	array1 = malloc(studs * marks * sizeof(int));	//pointer na začátek pole známek
	array2 = malloc(studs * sizeof(double));	//pointer na začátek pole průměrů
	
	while(i<studs){
		ui_1(i,marks,array1);
		i++;
	}

	calculate_averages(studs,marks,array1,array2);
	i = 0;
	printf("\n####################\nDosažené výsledky:\n");
	
	while(i<studs){
		print_marks(i,marks,array1,array2);
		i++;
	}
	
	printf("\n####################\n");
	free(array1);
	free(array2);
	return(0);
}

