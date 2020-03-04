/*
 * project euler 45
 * 
 * Notice that the hexagonal numbers are a subset of the triangular numbers,
 * so we just have to look at a hexagonal number that is pentagonal.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_hexagonal(long long int, long long int*, long long int);

int main(void){
	long long int *pentagonal, *hexagonal, n;
	long long int i;
	
	/*Create a list with the first n pentagonal numbers*/
	n = 50000;
	
	pentagonal = (long long int*)malloc(n*sizeof(long long int));
		if(pentagonal == NULL){printf("NoMem\n"); return -1;}
	hexagonal = (long long int*)malloc(n*sizeof(long long int));
		if(hexagonal == NULL){printf("NoMem\n"); return -1;}
	
	for(i=1; i<=n; i++){
		pentagonal[i-1] = i*(3*i-1)/2;
		hexagonal[i-1] = i*(2*i-1);
	}
	
	for(i=285; i<n; i++){
		if(is_hexagonal(pentagonal[i], hexagonal, n)){
			printf("%lld\n", pentagonal[i]);
			return 1;
		}
	}
	
	return 0;
}

int is_hexagonal(long long int h, long long int *hexagonal, long long int n){
	int k;
	
	for(k=0; k<n; k++){
		if(hexagonal[k] == h)
			return 1;
		if(hexagonal[k] > h)
			return 0;
	}
	
	return 0;
}
