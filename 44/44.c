/*
 * project euler 44
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_pentagonal(int, int*, int);

int main(void){
	int *pentagonal, n;
	int i, j;
	int D, S;
	
	/*Create a list with the first n pentagonal numbers*/
	n = 30000;
	
	pentagonal = (int*)malloc(n*sizeof(int));
		if(pentagonal == NULL){printf("NoMem\n"); return -1;}
	
	for(i=1; i<=n; i++)
		pentagonal[i-1] = i*(3*i-1)/2;
	
	for(i=1; i<10000; i++){
		for(j=i-1; j>=0; j--){
			D = pentagonal[i] - pentagonal[j];
			S = pentagonal[i] + pentagonal[j];
			if(is_pentagonal(D, pentagonal, n) && is_pentagonal(S, pentagonal, n)){
				printf("%d\n", D);
				return 1;
			}
		}
	}
	
	return 0;
}

int is_pentagonal(int p, int *pentagonal, int n){
	int k;
	
	for(k=0; k<n; k++){
		if(pentagonal[k] == p)
			return 1;
		if(pentagonal[k] > p)
			return 0;
	}
	
	return 0;
}
