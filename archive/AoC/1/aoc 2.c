#include <stdio.h>
#include <stdlib.h>

int main (){

	FILE *fp;
	int bagscount=1;
	int temp1,temp2=0;
	int n=0;
	
	fp = fopen("input.txt","r");
	
	for(1;;){
		if(feof(fp)){
			break;
		}
		temp2=temp1; //recurring memory slot
		temp1=fgetc(fp);
		printf("%c",temp1);
		if(temp1=='\n' && temp2!='\n'){
			n++;
		}
		if(temp1=='\n' && temp2=='\n'){
			bagscount++;
		}
	}
	rewind(fp);
	int bag[bagscount];
	int k=0;
		for(k;k<bagscount;k++){ //vynuluje pole
			bag[k]=0;
		}
	int item=0;
	int i=0;
	temp1,temp2=0;
	printf("---------------------\n");
	
	for(1;;){
		fscanf(fp,"%i",&item);
		if(feof(fp)){
			bag[i]=bag[i]+item;
			printf("BAG#%i: %i\n",i,bag[i]);
			break; //tady je break loopu
		}
		temp2=fgetc(fp);
		temp1=fgetc(fp);
		if(temp2=='\n' && temp1!='\n'){
			bag[i]=bag[i]+item;
			fseek(fp,-1,SEEK_CUR);
			temp1,temp2,item=0;
		}
		if(temp2=='\n' && temp1=='\n'){
			bag[i]=bag[i]+item;
			temp1,temp2,item=0;
			printf("BAG#%i: %i\n",i,bag[i]);
			i++;
		}
	}
	
	int max[5]={0,0,0,0,0};
	int tag[5]={0,0,0,0,0};
	int j=0;
	i=0;
	int sum;
	for(j;j<3;){
		if(bag[i]>max[j]){
			max[j]=bag[i];
			tag[j]=i;
		}
		i++;
		if(i>bagscount){
			bag[tag[j]]=0;
			i=0;
			sum=sum+max[j];
			printf("\n---------------------\nMAX %i @ BAG#%i: %i",j,tag[j],max[j]);
			j++;
		}
	}


	printf("\n---------------------\nSUM: %i",sum);
	return(i);
}



















