#include<math.h>
#include<stdlib.h>
#include<stdio.h>


typedef struct{
	int wlength;	//wavelength < to be input in NANOMETERS (10^(-9) m)
	double f;	//freq
	double E;	//energy
	int s;	//part of spectrum
}PHOTON;

double frequency(int wlength){
	double f = (double)300/wlength;
	return(f);
}

double energy(int wlength){
	double E = (double)1242/wlength;
	return(E);
}

int printphoton(int wlength, double f, double E, double s){
	printf("	> wavel. = %i [nm]\n	> frequ. = %f [10^15 Hz]\n	> energy = %f [eV]\n",wlength,f,E);
	if(s == 0){printf("	> spec. = gamma\n");}	//gamma 0
	if(s == 1){printf("	> spec. = xray\n");}	//xray 1
	if(s == 2){printf("	> spec. = UV\n");}	//UV 2
	if(s == 3){printf("	> spec. = blue\n");}	//vis blue 3
	if(s == 4){printf("	> spec. = green\n");}	//vis green 4
	if(s == 5){printf("	> spec. = red\n");}	//vis red 5
	if(s == 6){printf("	> spec. = IR\n");}	//IR 6
	if(s == 7){printf("	> spec. = microwave\n");}	//microwave 7
	if(s == 8){printf("	> spec. = radio\n");}	//radio 8
	printf("#########################\n");
	return(0);
}

int decidespectrum(int wlength){
	int s=0;	//gamma 0
	if(wlength > 1){s++;}	//xray 1
	if(wlength > 9){s++;}	//UV 2
	if(wlength > 400){s++;}	//vis blue 3
	if(wlength > 500){s++;}	//vis green 4
	if(wlength > 610){s++;}	//vis red 5
	if(wlength > 700){s++;}	//IR 6
	if(wlength > 1000000){s++;}	//microwave 7
	if(wlength > 1000000000){s++;}	//radio 8
	return(s);
}



int main(){
	PHOTON g;

	//time for another epic GUI
	printf("obligatory hello world, i'm photomatic,\ninput wavelength in NANOmeters (10^-9, whole number):\n");
	scanf("%i",&g.wlength);
	
	printf("\n#########################\n");

	g.f = frequency(g.wlength);
	g.E = energy(g.wlength);
	g.s = decidespectrum(g.wlength);

	printphoton(g.wlength,g.f,g.E,g.s);
	
	return(0);
}
