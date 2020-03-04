/*
 * project euler 42
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_triangular(int, int*, int);

int main(void){
	int *triangular, n;
	int S, i, count;
	FILE *pf;
	char aux;
	
	/*Create a list with the first n pentagonal numbers*/
	n = 1000;
	
	triangular = (int*)malloc(n*sizeof(int));
		if(triangular == NULL){printf("NoMem\n"); return -1;}
	
	for(i=1; i<=n; i++)
		triangular[i-1] = i*(i+1)/2;
	
	/*Open file*/
	pf = fopen("words.txt", "r");
		if(pf == NULL){printf("No File\n"); return -1;}
	
	count = 0;
	while(fscanf(pf, "%c", &aux) != EOF){
		S = 0; 
		
		fscanf(pf, "%c", &aux);
		while(aux != '"'){
			S += (int)aux-64;
			fscanf(pf, "%c", &aux);
		}
		
		if(is_triangular(S, triangular, n))
			count++;
		
		fscanf(pf, "%c", &aux);
	}
		
	printf("%d\n", count);
	
	return 0;
}

int is_triangular(int t, int *triangular, int n){
	int k;
	
	for(k=0; k<n; k++){
		if(triangular[k] == t)
			return 1;
		if(triangular[k] > t)
			return 0;
	}
	
	return 0;
}
