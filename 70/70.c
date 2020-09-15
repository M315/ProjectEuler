/*
 * project euler 70
 *
 * As we want to minimize n/phi(n) and phi(n) = n*(1-1/p1)*(1-1/p2)*...
 * where p1, p2... are the prime factors of n.
 * We must maximixe the product (1-1/p1)*(1-1/p2)*...
 * In order to do so we reacall that for every new prime pn the product decreases,
 * so we must look for a number comosed by two large primes or three, etc. beacuse
 * the number cant be prime as p and p-1 won't ever be premutations of eachother.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int);
int are_permutation(int, int);

int main(void){
	int *primes, N;
	int n, phi, n_min, i, j;
	double min = 2.;
	
	/*Compute the primes smaller than N*/
	N = 5000;
	
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	for(i = primes[0] - 1; i > 0; i--){
		for(j = i + 1; j <= primes[0]; j++){
			n = primes[i] * primes[j];
			phi = (primes[i] - 1) * (primes[j] - 1);

			if(are_permutation(n, phi) && n < 10000000 && (double)n / (double)phi < min){
				n_min = n;
				min = (double)n / (double)phi;
			}
		}
	}

	printf("%d (%g)\n", n_min, min);

	free(primes);

	return 1;
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

int are_permutation(int a, int b){
	int len = 0, *dig_a, *dig_b, coincidences = 0, i, j;

	dig_a = (int*)malloc(len * sizeof(int));
	dig_b = (int*)malloc(len * sizeof(int));

	while(a != 0 && b != 0){
		len++;

		dig_a = (int*)realloc(dig_a, len * sizeof(int));
		dig_b = (int*)realloc(dig_b, len * sizeof(int));

		dig_a[len-1] = a % 10;
		dig_b[len-1] = b % 10;

		a = a / 10;
		b = b / 10;
	}
	
	if(a != 0 || b != 0)
		return 0;
	
	for(i = 0; i < len; i++){
		for(j = 0; j < len; j++){
			if(dig_a[i] == dig_b[j]){
				dig_b[j] = -1;
				coincidences++;
				break;
			}
		}
	}

	if(coincidences == len)
		return 1;

	return 0;
}
