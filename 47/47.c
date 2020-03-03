/*
 * project euler 47
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int* garbellErastotenes(int);
int num_primes_factor(int, int*);

int main(void){
	int k, combo;
	int *primes, N;
	clock_t t1, t2;
	
	t1 = clock();
	
	/*Compute the primes smaller than N*/
	N = 1000;
	
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	combo = 0;
	for(k=1; k<1000000; k++){
		if(num_primes_factor(k, primes)>=4){
			combo++;
			if(combo == 4){
				t2 = clock();
				printf("The solution is %d and it takes %g ms\n", k-3, 1000.*((double)(t2-t1))/CLOCKS_PER_SEC);
				return 1;
			}
		}else{
			combo = 0;
		}
	}
	
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

int num_primes_factor(int n, int *primes){
	int i, count, aux;
	
	aux = n;
	
	count = 0;
	i = 1;
	while(i<primes[0] && aux>0){
		if(aux%primes[i] == 0){
			count++;
			aux = aux/primes[i];
			while(aux%primes[i] == 0)
				aux = aux/primes[i];
		}
		i++;
	}
	
	return count;
}
