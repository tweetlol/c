#include<math.h>
#include<stdlib.h>
#include<stdio.h>


typedef struct{
	int wlength;	//wavelength < to be input in NANOMETERS (10^(-9) m)
	double f;	//freq
	double E;	//energy
//	char[16] spec;	//part of spectrum (~Xray/vis/UV~)
}PHOTON;

double frequency(int wlength){
	double f = (double)300/wlength;
	return(f);
}

double energy(int wlength){
	double E = (double)1242/wlength;
	return(E);
}

int printphoton(int wlength, double f, double E){
	printf("	> wavel. = %i [nm]\n	> frequ. = %f [10^15 Hz]\n	> energy = %f [eV]\n#########################\n",wlength,f,E);
	return(0);
}

int main(){
	PHOTON g;

	//time for another epic GUI
	printf("obligatory hello world, i'm photomatic,\ninput wavelength in NANOmeters (10^-9, whole number):\n");
	scanf("%i",&g.wlength);
	
	printf("\n#########################\n");

	g.f = frequency(g.wlength);
	g.E = energy(g.wlength);

	printphoton(g.wlength,g.f,g.E);
	
	return(0);
}
