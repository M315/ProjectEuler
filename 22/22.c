#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	unsigned long long int total=0, nscr;
	int i, j, k;
	char fname[100], temp, name[50];
	FILE *pf;
	
	printf("Give the name of the input file (max 100 characters):\n");
	scanf("%s",fname);
	pf= fopen(fname, "r");
		if(pf==NULL){printf("No file\n"); exit(-1);}
	
	for(i=1; i<5001; i++){
		fscanf(pf, "%c", &temp);
		j = -1;
		do{
			j++;
			fscanf(pf, "%c", &name[j]);
		}while(name[j]!=',' && name[j]!=EOF);
/*printf("%s\n", name);*/
		
		/*Get the value of avery letter and sum it*/
		nscr = 0;
		for(k=0; k<j-1; k++){
			nscr+=((int)name[k]-64);
printf("+ %d", (int)name[k]-64);
		}
		
		total = total + (i*nscr);
		
		/*free(name);*/
	}
	
	fclose(pf);
	
	printf("\n%lld\n", total);
	
	return 0;
}
