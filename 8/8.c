#include <stdio.h>
#include <stdlib.h>

int main(void){
	int s[13], i, j;
	long int prod=1, prodmax;
	FILE *pf;
	
	pf= fopen("serie.txt", "r");
		if(pf==NULL){printf("No file\n"); return -1;}
	
	for(i=0; i<13; i++){
		s[i]= (fgetc(pf))-48;
		printf("%d", s[i]);
		prod= prod*s[i];
	}
	prodmax= prod;
	
	for(i=13; i<1000; i++){
		for(j=0; j<12; j++)
			s[j]= s[j+1];
		s[12]= (fgetc(pf))-48;
		
		prod= 1;
		for(j=0; j<13; j++)
			prod= prod*s[j];
		
		if(prod>prodmax)
			prodmax= prod;
	}
	
	printf("\n%ld\n", prodmax);
	
	return 0;
}
