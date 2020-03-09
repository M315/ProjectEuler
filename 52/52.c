/*
 * project euler 51
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int six_perm_mult(unsigned long long int num[]);
int cmpfunc(const void*, const void*);

int main(void){
	int i;
	unsigned long long int n, N, num[6];
	
	N = 1000000;
	for(n=1; n<N; n++){
		num[0] = n;
		for(i=2; i<=6; i++)
			num[i-1] = n*i;
		
		if(six_perm_mult(num)){
			printf("%llu\n", n);
			return 1;
		}
	}
	
	return 0;
}

int six_perm_mult(unsigned long long int num[]){
	int *digits, *dif_digits, aux, n, N;
	int i, j;
	
	/*put each digit of the first number in a vector*/
	digits = (int*)malloc(sizeof(int));
		if(digits == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	aux = num[0];
	
	digits[0] = aux%10;
	
	aux = aux/10;
	
	while(aux>0){
		n++;
		digits = (int*)realloc(digits, n*sizeof(int));
			if(digits == NULL){printf("Err: No mem\n"); return -1;}
		
		digits[n-1] = aux%10;
		aux = aux/10;
	}
	
	qsort(digits, n, sizeof(int), cmpfunc);
	
	for(i=5; i>=1; i--){
		/*put each digit of the next number in a vector*/
		dif_digits = (int*)malloc(sizeof(int));
			if(dif_digits == NULL){printf("Err: No mem\n"); return -1;}
		
		N = 1;
		aux = num[i];
		
		dif_digits[0] = aux%10;
		
		aux = aux/10;
		
		while(aux>0){
			N++;
			dif_digits = (int*)realloc(dif_digits, N*sizeof(int));
				if(dif_digits == NULL){printf("Err: No mem\n"); return -1;}
			
			dif_digits[N-1] = aux%10;
			aux = aux/10;
		}
		
		if(n!=N)
			return 0;
		
		/*Sort the digits and find if they are the same as the original number*/
		qsort(dif_digits, N, sizeof(int), cmpfunc);
		for(j=0; j<N; j++)
			if(digits[j] != dif_digits[j])
				return 0;
	}
	
	return 1;
}


int cmpfunc(const void *a, const void *b){
	return ( *(int*)a - *(int*)b);
}
