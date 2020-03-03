/*
 * project euler 37
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primecheck(int);
int left_check(int);
int right_check(int);

int main(void){
	int count;
	long long int sum, k, N=1000000;
	/*int *primes, n;*/
	
	/*Compute the N first primes*/
	/*primes = (int*)malloc(sizeof(int));
		if(primes == NULL){printf("Err: No Mem\n"); return -1;}
	
	n = 1;
	primes[0] = 2;
	
	for(k=3; k<N; k++){
		if(primecheck(k) == 1){
			n++;
			primes = (int*)realloc(n*sizeof(int));
				if(primes == NULL){printf("Err: No Mem\n"); return -1;}
			
			primes[n-1] = k;
		}
	}*/
	
	sum = 0;
	count = 0;
	for(k=10; k<N; k++){
		if(right_check(k) == 1 && left_check(k) == 1){
			count ++;
			sum += k;
		}
		if(count == 11)
			break;
	}
	
	printf("%lld - %d\n", sum, count);
	
	return 0;
}

int primecheck(int a){
	int n;
	if(a == 1)
		return 0;
	if(a == 2)
		return 1;
	if(a%2==0)
		return 0;
	for(n=3; n<=sqrt(a); n=n+2)
		if(a%n==0)
			return 0;
	return 1;
}

int left_check(int p){
	int aux;
	
	aux = p;
	
	while(aux>0){
		if(primecheck(aux) == 0)
			return 0;
		
		aux = aux/10;
	}
	
	return 1;
}

int right_check(int p){
	int aux, i, j, mult, k;
	int *num, n;
	
	/*put each digit of the number in a vector*/
	num = (int*)malloc(sizeof(int));
		if(num == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	aux = p;
	
	num[0] = aux%10;
	
	aux = aux/10;
	
	while(aux>0){
		n++;
		num = (int*)realloc(num, n*sizeof(int));
			if(num == NULL){printf("Err: No mem\n"); return -1;}
		
		num[n-1] = aux%10;
		aux = aux/10;
	}
	
	/*check the property*/
	for(k=0; k<n; k++){
		aux = 0;
		for(i=0; i<=k; i++){
			mult = 1;
			for(j=0; j<i; j++)
				mult = mult*10;
			aux += mult*num[i];
		}
		
		if(primecheck(aux) == 0)
			return 0;
	}
	
	free(num);
	
	return 1;
}
