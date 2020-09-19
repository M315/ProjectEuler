/*
 * project euler 87
 *
 * Preaty brute force, compute all the possible convinations of prime sumations
 * making sure to complete the conditions and if the number was already been seen
 * dont put it.
 *
 * WARNING:	make sure that the primes that are been used are in the bounderies
 * 			when powered cause that may produce overflow on the interger making
 *			the sum.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int);

int main(void){
	int *primes, i, j, k;
	long long int N, n, *nums, count = 0;
	
	/*Compute the primes smaller than n = sqrt(50.000.000)*/
	N = 50000000;
	n = (long long int)sqrt(N);
	
	primes = garbellErastotenes(n);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	/*make a list with all the numbers*/
	nums = (long long int*)calloc(N, sizeof(long long int));
		if(nums == NULL){printf("Err: No Mem\n"); return 1;}
	

	for(i = 1; i <= primes[0]; i++){
		for(j = 1; primes[j] < pow((double)N, 1./3.); j++){
			for(k = 1; primes[k] < pow((double)N, 1./4.); k++){
				/*n = p1^2 + p2^3 + p3^4*/
				n = primes[i] * primes[i];
				n += primes[j] * primes[j] * primes[j];
				n += primes[k] * primes[k] * primes[k] * primes[k];

				if(n < N)
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}

				/*n = p1^2 + p3^3 + p2^4*/
				n = primes[i] * primes[i];
				n += primes[k] * primes[k] * primes[k];
				n += primes[j] * primes[j] * primes[j] * primes[j];

				if(n < N && primes[j] < pow((double)N, 1./4.))
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}
				
				/*n = p2^2 + p1^3 + p3^4*/
				n = primes[j] * primes[j];
				n += primes[i] * primes[i] * primes[i];
				n += primes[k] * primes[k] * primes[k] * primes[k];

				if(n < N && primes[i] < pow((double)N, 1./3.))
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}
				
				/*n = p2^2 + p3^3 + p1^4*/
				n = primes[j] * primes[j];
				n += primes[k] * primes[k] * primes[k];
				n += primes[i] * primes[i] * primes[i] * primes[i];

				if(n < N && primes[i] < pow((double)N, 1./4.))
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}
				/*n = p3^2 + p1^3 + p2^4*/
				n = primes[k] * primes[k];
				n += primes[i] * primes[i] * primes[i];
				n += primes[j] * primes[j] * primes[j] * primes[j];

				if(n < N && primes[i] < pow((double)N, 1./3.) && primes[j] < pow((double)N, 1./4.))
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}
				/*n = p3^2 + p2^3 + p1^4*/
				n = primes[k] * primes[k];
				n += primes[j] * primes[j] * primes[j];
				n += primes[i] * primes[i] * primes[i] * primes[i];

				if(n < N && primes[i] < pow((double)N, 1./4.))
					if(nums[n] == 0){
						count++;
						nums[n] = 1;
					}
			}
		}
	}

	printf("%lld\n", count);
	
	free(nums);
	free(primes);

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
