/*
 * project euler 36
 */


#include <stdio.h>
#include  <stdlib.h>

int check_palindrome(int a){
	int *num, *bin;
	int aux, n, i;
	
	/*put each digit of the number in a vector*/
	num = (int*)malloc(sizeof(int));
		if(num == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	aux = a;
	
	num[0] = aux%10;
	
	aux = aux/10;
	
	while(aux>0){
		n++;
		num = (int*)realloc(num, n*sizeof(int));
			if(num == NULL){printf("Err: No mem\n"); return -1;}
		
		num[n-1] = aux%10;
		aux = aux/10;
	}
	
	/*check if its a palindrome*/
	for(i=0; i<n/2; i++)
		if(num[i] != num[n-1-i])
			return 0;
	
	free(num);
	
	/*convert the decimal digit in a binari one stored in a vector*/
	bin = (int*)malloc(sizeof(int));
		if(bin == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	aux = a;
	
	bin[0] = aux%2;
	
	aux = aux/2;
	
	while(aux>0){
		n++;
		bin = (int*)realloc(bin, n*sizeof(int));
			if(bin == NULL){printf("Err: No mem\n"); return -1;}
		
		bin[n-1] = aux%2;
		aux = aux/2;
	}
	
	for(i=0; i<n/2; i++)
		if(bin[i] != bin[n-1-i])
			return 0;
	
	free(bin);
	
	return 1;
}

int main(void){
	int k;
	long long int sum;
	
	sum = 0;
	for(k=0; k<1000000; k++)
		if(check_palindrome(k) == 1)
			sum += k;
	
	printf("%lld\n", sum);
	
	return 0;
}

