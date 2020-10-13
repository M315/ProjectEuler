#include <stdio.h>
#include <stdlib.h>

long prime_summation(void);
long *garbellErastotenes(long);

int main(void){
	printf("%ld\n", prime_summation());

	return 0;
}

long prime_summation(void){
	long *num, *prime, curr, i, max = 100;
	
	num = (long*)calloc(max, sizeof(long));
		if(num == NULL){printf("Err: NoMem\n"); return -1;}
	
	prime = garbellErastotenes(max);

	for(i = 1; i <= prime[0]; i++)
		num[prime[i]]++;
	
	for(curr = 2; curr < max; curr++){
		for(i = 1; prime[i] <= curr/2 && i <= prime[0]; i++){
			num[curr] += num[curr - prime[i]];
		}
		
		/*if(num[curr] > 5000)
			return curr;*/
		
		printf("%ld \t%ld\n", curr, num[curr]);
	}

	return 1;
}

long* garbellErastotenes(long N){
	long *I, *p;
	long i, j, n;
	
	I = (long*)calloc(N+1,sizeof(long));
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
	
	p = (long*)malloc(sizeof(long));
		if(p == NULL){printf("Err: No Mem\n"); return NULL;}
	
	n = 1;
	p[0] = n-1;
	
	for(i=0; i<=N; i++){
		if(I[i] != 0){
			n++;
			p = (long*)realloc(p, n*sizeof(long));
				if(p == NULL){printf("Err: No Mem\n"); return NULL;}
			
			p[n-1] = I[i];
			/*save the number of primes that we get in the initial position*/
			p[0] = n-1;
		}
	}
	
	free(I);
	
	return p;
}
