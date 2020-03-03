/*
 * project euler 41
 * 
 * If the sum of the digits of a number is divisible by 3 then the number is divisible by 3.
 * So as 1+2+3+4+5+6+7+8+9 = 45 and 1+2+3+4+5+6+7+8 = 36 and 1+2+3+4+5+6+7 = 28 we can start
 * finding numbers lower than 7654321, which is lot smaller than 9876543
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* garbellErastotenes(int);
int is_pandigital(int);

int main(void){
	int p;
	int *primes, N;
	
	/*Compute the primes smaller than N*/
	N = 7654321;
	
	primes = garbellErastotenes(N);
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	for(p=primes[0]; p>0; p--){
		if(is_pandigital(primes[p])){
			printf("%d\n", primes[p]);
			return 1;
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

int is_pandigital(int p){
	int *num, n;
	int pan, i, j, check;
	
	/*put each digit of the number in a vector*/
	num = (int*)malloc(sizeof(int));
		if(num == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	pan = p;
	
	num[0] = pan%10;
	
	pan = pan/10;
	
	while(pan>0){
		n++;
		num = (int*)realloc(num, n*sizeof(int));
			if(num == NULL){printf("Err: No mem\n"); return -1;}
		
		num[n-1] = pan%10;
		pan = pan/10;
	}
	
	/*chec that all the digits are different between them*/
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if(num[i] == num[j])
				return 0;
	
	for(i=1; i<=n; i++){
		check = 0;
		
		for(j=0; j<n; j++)
			if(i == num[j]){
				check = 1;
				break;
			}
		
		if(!check)
			return 0;
	}
	
	return 1;
}
