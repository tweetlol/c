#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int clear(double pole[],int delka){	//messiest possible backend for PROFIT

	int i=0;
	printf("vytvářím a čistím pole: ");
	while(i<delka){
		pole[i] = 0;
		printf("%.0f ",pole[i]);
		i++;
	}
	return(2);
}

double average(double pole[],int delka){
	int i=0;
	int znamek=0;
	double a=0;
	int ii=0;
	while(i<delka){
		ii = pole[i];	//pole není integer a nejde dát do switche
		switch(ii){	//spočítá nenuly v poli[]
			case 0:
				break;
			default:
				znamek++;
				a = a + pole[i];
				break;
		}
		i++;
	}
	a = a/znamek;
	return(a);
}
						//			"dosažený průměr: 1.0"
int print_znamky(double pole[],int delka){	//printne pole na řádek "známky: 1 1 1 1"
	int i=0;
	double a=0;
	a = average(pole,delka);
	printf("dosažený průměr: %.2lf\n",a);
	printf("jednotlivé známky: ");
	while(i<delka){
		printf("%.0f ",pole[i]);
		i++;
	}
	return(4);
}

int newscreen(){	//odřádkuje celý screen
	int i=0;
	while(i<24){
		printf("\n");
		i++;
	}
	return(69);
}

int frame(double pole[],int delka){	//fanciest possible ui for PROFIT
	int i=0;
	while(i<delka){
		newscreen();
		print_znamky(pole,delka);
		printf("\npřidat známku: ");
		scanf("%lf",&pole[i]);
		i++;
	}
	
	return(3);
}


int main(){
	int debug=0;
	int d;	//jako denominator
	
	printf("#########################\nobligatory hello world, im arithmatic\nkolik známek?: ");
	scanf("%i",&d);

	double znamky[d];	//pole doublů, protože je budu dělit
	clear(znamky,d);

	printf("\n#########################\n");
	frame(znamky,d);

	newscreen();
	printf("#########################\n\n");
	print_znamky(znamky,d);
	

	return(debug);
}
