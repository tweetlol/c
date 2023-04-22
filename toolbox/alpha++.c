#include<stdio.h>
#include<stdlib.h>
#include<math.h>


typedef struct{
	int A;	//atomic mass
	int Z;	//proton number
	int N;	//neutrons (A-Z)
	double R;

}NUCLEUS;

int neutrons(int A, int Z){	//returns number of neutrons in a nucleus
	int N=A-Z;
	return(N);
}

int printnucleus(int A, int Z, int N, double R){
	printf("	A = %i\n	Z = %i\n	N = A-Z = %i\n	R = %f fm\n#########################\n",A,Z,N,R);
	return(0);
}

double radius(int A){	//returns radius of a nucleus
	double R=1.2*pow(A,pow(3,-1));
	return(R);
}

double fusionenergy(int Q1, double R1, int Q2, double R2){
	double E=(Q1*Q2)/(R1+R2);
	E=1.4384*E;
	return(E);	
}

double main(){
	NUCLEUS X;
	NUCLEUS alfa;
	NUCLEUS Y;
	double E;
	

	alfa.A = 4;alfa.Z=2;	//alfa particle definition
	alfa.N = neutrons(alfa.A,alfa.Z);
	alfa.R = radius(alfa.A);

	//the epic GUI
	printf("obligatory hello world, i'm alpha++,\n(A - atomic mass, Z - proton number):\n#########################\n	> nucleus 1 - 4 2 He, aka alpha particle:\n");
	printnucleus(alfa.A, alfa.Z, alfa.N, alfa.R);
	printf("	> nucleus 2 - target:\n");
	
	scanf("%i %i",&X.A,&X.Z);
	
	X.N = neutrons(X.A, X.Z);	//target nucleus description
	X.R = radius(X.A);
	
	printnucleus(X.A, X.Z, X.N, X.R);

	E = fusionenergy(X.Z, X.R, alfa.Z, alfa.R);
	printf("alpha particle would need E = %f MeV\nof kinetic energy to reach target nucleus\n#########################\n	> product:\n",E);
	
	Y.A = X.A + alfa.A;	//product nucleus description
	Y.Z = X.Z + alfa.Z;
	Y.N = neutrons(Y.A, Y.Z);
	Y.R = radius(Y.A);

	printnucleus(Y.A, Y.Z, Y.N, Y.R);
	
	return(0);
}



