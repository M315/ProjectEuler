/*
 * project euler 41
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int);

int main(void){
	int *primes, N, i;
	long long int sum = 0;
	
	/*Compute the primes smaller than N*/
	N = 2000000;
	
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	for(i = 1; i <= primes[0]; i++)
		sum += primes[i];

	printf("%lld\n", sum);

	return 0;
}

int* garbellErastotenes(int N){
	int *I, *p;
	int i, j, n;
	
	I = (int*)calloc(N+1,sizeof(int));
		if(I == NULL){printf("Err: No Mem\n"); return NULL;}
	
	for(i=2; i<=N; i++)
		I[i] = i;
	
	i = 0;
	
	while(I[i]*I[i]<=N){
		if(I[i]!=0){
			for(j=2; j<N; j++){
				if(j*I[i]>N){
					break;
				}else{
					I[j*I[i]] = 0;
				}
			}
		}
		i++;
	}
	
	p = (int*)malloc(sizeof(int));
		if(p == NULL){printf("Err: No Mem\n"); return NULL;}
	
	n = 1;
	p[0] = n-1;
	
	for(i=0; i<=N; i++){
		if(I[i] != 0){
			n++;
			p = (int*)realloc(p, n*sizeof(int));
				if(p == NULL){printf("Err: No Mem\n"); return NULL;}
			
			p[n-1] = I[i];
			/*save the number of primes that we get in the initial position*/
			p[0] = n-1;
		}
	}
	
	free(I);
	
	return p;
}
