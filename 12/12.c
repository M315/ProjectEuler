/*
 * project euler 12
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int);
int number_divisors(int, int*);

int main(void){
	int *primes, N, i = 3, tri = 3, num_div = 1;
	
	/*Compute the primes smaller than N*/
	N = 10000;
	
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	while(num_div < 500){
		tri += i;
		i++;
		num_div = number_divisors(tri, primes);
	}
	
	printf("%d\n", tri);

	free(primes);

	return 0;
}

int number_divisors(int num, int *primes){
	int num_div = 0, *prime_factors, n_pf = 0;
	int i = 1, n;

	prime_factors = (int*)malloc(n_pf*sizeof(int));

	n = num;
	while(n != 1 && i < primes[0]){
		if(n % primes[i] == 0){
			n = n/primes[i];

			n_pf++;
			prime_factors = (int*)realloc(prime_factors, n_pf*sizeof(int));
			prime_factors[n_pf - 1] = 1;
			
			while(n % primes[i] == 0){
				n = n/primes[i];
				prime_factors[n_pf - 1]++;
			}
		}

		i++;
	}

	num_div = prime_factors[0] + 1;
	for(i = 1; i < n_pf; i++)
		num_div = num_div * (prime_factors[i] + 1);
	
	free(prime_factors);
	
	return num_div;
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
