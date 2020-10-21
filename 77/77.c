#include <stdio.h>
#include <stdlib.h>

long prime_summation(void);
long *garbellErastotenes(long);
int findposs(int, int, long*);

int main(void){
	printf("%ld\n", prime_summation());

	return 0;
}

long prime_summation(void){
	long *prime, curr, max = 90;
	int p, count;
	
	prime = garbellErastotenes(max);

	p = 1;
	for(curr = 2; curr < max; curr++){
		if(prime[p] <= curr)
			p++;

		count = findposs(curr, p, prime);

		/*if(num[curr] > 5000)
			return curr;*/
		
		printf("%ld \t%d\n", curr, count);
	}

	return 1;
}

int findposs(int num, int min_ind, long *prime){
    int i, sum = 0;

    for(i = min_ind; i > 0; i--){
        if (num - prime[i] == 0) sum++;
        if (num - prime[i] > 0) sum += findposs(num - prime[i], i, prime);
    }
    return sum; 
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
