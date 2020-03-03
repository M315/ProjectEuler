/*
 * project euler 38
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int unique9(unsigned int);
int pandigital_product(unsigned int);

int main(void){
	unsigned int n, num, max = 918273645;
	
	for(n=0; n<362880; n++){
		num = unique9(n);
		if(num > max){
			if(pandigital_product(num)){
				max = num;
			}
		}
	}
	
	printf("%u\n", max);
	
	return 0;
}

unsigned int unique9(unsigned int seed){
	/* function that computes the seed (0<= seed < 9! = 362880) combiation of 9 different digit number
	 * https://stackoverflow.com/questions/31826746/trying-to-generate-9-digit-numbers-with-each-unique-digits*/
    unsigned char digit[9] = { 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U };
    unsigned int  result = 0U;
    unsigned int  n = 9U;
    while (n) {
        const unsigned int i = seed % n;
        seed = seed / n;
        result = 10U * result + digit[i];
        digit[i] = digit[--n];
    }
    return result;
}

int pandigital_product(unsigned int num){
	int i, j, k, mult, m, dig_count, aux_m, *digits_m;
	int *digits, n;
	unsigned aux;
	
	/*put each digit of the number in a vector*/
	digits = (int*)malloc(9*sizeof(int));
		if(digits == NULL){printf("Err: No mem\n"); return -1;}
	
	n = 1;
	aux = num;
	
	digits[8] = aux%10;
	
	aux = aux/10;
	
	while(aux>0){
		n++;
		
		digits[9-n] = aux%10;
		aux = aux/10;
	}
	
	/*Take the first digit and see if it multiplied by 1,2,...,n and concatenated gives num
	 * if not do it with the first 2, if not with the first 3 and finally with the first 4.
	 * 
	 * No need more than 4 cause we are looking for the largest one and already know that 918273645
	 * satisfies the properti, so any number bigger than 91827 times two concatenated with 91287
	 * will exceed the 9 digits.*/
	
	for(i=1; i<5; i++){
		/*Compute the number we will multipli by 1,2...*/
		mult = 0;
		m = 1;
		for(j=i-1; j>=0; j--){
			mult += digits[j]*m;
			m = m*10;
		}
		
		/*check if multipling mult by 2,3... the number still maches num*/
		dig_count = i;
		
		n = 2;
		while(dig_count < 9){
			aux_m = mult*n;
			
			/*put each digit of the number in a vector*/
			digits_m = (int*)malloc(sizeof(int));
				if(digits_m == NULL){printf("Err: No mem\n"); return -1;}
			
			m = 1;
			
			digits_m[0] = aux_m%10;
			
			aux_m = aux_m/10;
			
			while(aux_m>0){
				m++;
				digits_m = (int*)realloc(digits_m, m*sizeof(int));
					if(digits_m == NULL){printf("Err: No mem\n"); return -1;}
				
				digits_m[m-1] = aux_m%10;
				aux_m = aux_m/10;
			}
			
			/*if the concatenation exceed 9 digits break*/
			if(dig_count + m > 9)
				break;
			
			for(k=0; k<m; k++){
				/*if the digits dont mach break*/
				if(digits_m[m-1-k] != digits[dig_count + k]){
					dig_count = 10;
					break;
				}
			}
			
			dig_count += m;
			n++;
			
			free(digits_m);
		}
		
		/*if the result have 9 digits we found it*/
		if(dig_count == 9){
			return 1;
		}
	}
	
	free(digits);
	
	return 0;
}
