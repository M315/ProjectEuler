/*
 * project euler 55
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int is_Lychrel(int);

int main(void){
	int k, count;
	
	count = 0;
	for(k=1; k<10000; k++)
		if(is_Lychrel(k)==0)
			count++;
	
	printf("%d\n", count);
	
	return 0;
}

int is_Lychrel(int a){
	int *num;
	int n, i, j, check;
	uint64_t aux, A, R, mult;
	
	A = a;
	for(j=0; j<50; j++){
		/*put each digit of the number in a vector*/
		num = (int*)malloc(sizeof(int));
			if(num == NULL){printf("Err: No mem\n"); return -1;}
		
		n = 1;
		aux = A;
		
		num[0] = aux%10;
		
		aux = aux/10;
		
		while(aux!=0){
			n++;
			num = (int*)realloc(num, n*sizeof(int));
				if(num == NULL){printf("Err: No mem\n"); return -1;}
			
			num[n-1] = aux%10;
			aux = aux/10;
		}
		
		/*We don't want to see if the first number it's a palindrome*/
		if(j>0){
			/*check if its a palindrome*/
			check = 1;
			for(i=0; i<n/2; i++)
				if(num[i] != num[n-1-i]){
					check = 0;
					break;
				}
			
			/*if its a palindrome retrun the number of iterations needed to find the palindrome number*/
			if(check)
				return j;
		}
		
		/*reverse the digits and put them in to a number*/
		R = 0U;
		mult = 1U;
		for(i=n-1; i>=0; i--){
			R += num[i]*mult;
			mult = mult*10U;
		}
		
		free(num);
		
		/*Sum the original number and the reversed one and repeat*/
		A = A + R;
	}
	
	return 0;
}


