#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int main(){

	char mem[255];
	int i=0;
	int n=0;
	int diff=0;
	int sign=1;
	int temp1,temp2,temp3 = 0;
	FILE *fp;
//	FILE *out;

for(1;;){
	
	for(i;i<255;i++){ //good ol memory wipe
		mem[i]=0;
	}
	
	i=0;	
	fp = fopen("secret message.txt","r");
//	out = fopen("encrypted message.txt","w");
	printf("\n-----------------------------------------\n");
	printf("FILE LOAD: secret message.txt \nChoose encrypting complexity: \n (0) none \n (1) boyscout \n (2) caesar++ \n (3) ENIG- \n");
	scanf("%i",&diff);
	
	switch(diff){
		default:
			n=0;
			break;
		case 1:
			n=2;
			break;
		case 2:
			n=1;
			break;
		case 3:
			n=1;
			break;
	}
	for(i;i<255;i++){
		
		temp1 = fgetc(fp);
		
		if(feof(fp)){
			break;
		}
		if(temp1!=' ' && temp1!='\n'){
				temp1 = temp1 - 97;
				temp2 = (temp1 + sign*n)%26;
				if(temp2>=0){
				temp3 = temp2 + 97;
				}else{
				temp3 = temp2 + 123;
				}
				mem[i] = temp3;
				switch(diff){
					case 0:
						break;
					case 1:
						break;
					case 2:
						n++;
						break;
					case 3:
						n++;
						sign = -sign;
						break;
				}	
		}else{
				mem[i] = temp1;
				if(diff>1){
					n=1;
					sign=1;
				}
		}
				
		printf("%c",mem[i]);
//		fprintf(out,"%i","1"); 

	}
}
	return(diff);
}













