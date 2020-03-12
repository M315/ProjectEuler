/*
 * Project Euler 58
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* garbellErastotenes(int);
void spiral(int, int*);
int is_prime(int, int*);
 
int main(void){
	int *primes, N;
	int n=30001;
	clock_t ti, tf;
	
	ti = clock();
	
	N = 1000000000;
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	tf = clock();
	
	printf("Primes generated in %g sec.\n", ((double)tf - (double)ti)/CLOCKS_PER_SEC);
	
	ti = clock();
	
	spiral(n,primes);
	
	tf = clock();
	
	printf("Done in %g sec\n", ((double)tf - (double)ti)/CLOCKS_PER_SEC);
	
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

/*generates the diagonals of the spiral*/
void spiral(int n, int *primes){
	int i, k, diag;
	int count=1, prime_count=0;
	
	k = 1;
	do{
		k += 2;
		
		diag = k*k;
		for(i=1; i<4; i++){
			diag = diag-k+1;
			
			if(is_prime(diag, primes)){
				prime_count++;
			}
		}
		
		count += 4;
		
	}while(((double)prime_count/(double)count)>0.1 && k<n);
	
	printf("%d - %g\n", k, (double)prime_count/(double)count);
	
	return;
}

int is_prime(int p, int *primes){
	int i, start;
	
	if(p<100){
		start = 1;
	}else{
		/*use the prime counting function to find an aproximation of how many lower primes thatn p are*/
		start = (int)(p/log((double)p));
	}
	
	for(i=start; i<=primes[0]; i++){
		if(p == primes[i])
			return 1;
		if(primes[i]>p)
			return 0;
	}
	
	return 0;
}
