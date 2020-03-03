#include <stdio.h>
#include <stdlib.h>

int main(void){
	int **a, i;
	unsigned long long int sum;
	FILE *pf;
	
	a= (int**)malloc(15*sizeof(int*));
		if(a==NULL){printf("No mem\n"); exit(-1);}
	for(i=0; i<15; i++){
		a[i]= (int*)malloc((i+1)*sizeof(int));
			if(a[i]==NULL){printf("No mem\n"); exit(-1);}
	}
	
	for(i=0; i<15; i++){
		
	
	
	return 0;
}
