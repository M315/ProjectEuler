/*
 * project euler 80
 *
 * See: https://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Digit-by-digit_calculation
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "gmp.h"

int main(void){
	unsigned long int N, sum = 0, x, digits;
	mpz_t p, y, c;
	
	mpz_init(p);
	mpz_init(y);
	mpz_init(c);
	
	for(N = 2; N < 100; N++){
		mpz_set_ui(p, 0U);
		mpz_set_ui(c, N);

		digits = 0;

		/*A perfect square is not irrational and must not e counted*/
		if(N == (int)sqrt(N) * (int)sqrt(N))
			digits = 100;

		while(mpz_cmp_ui(c, 0U) != 0 && digits < 100){
			for(x = 1U; x < 10U; x++){
			
				/*Compute x(20p+x)*/
				mpz_mul_ui(y, p, 20U);
				mpz_add_ui(y, y, x);
				mpz_mul_ui(y, y, x);
	
				/*If the result is smaller than c we have x and y*/
				if(mpz_cmp(y, c) > 0){
					x--;
					
					/*Compute y*/
					mpz_mul_ui(y, p, 20U);
					mpz_add_ui(y, y, x);
					mpz_mul_ui(y, y, x);
					
					break;
				}
			}

			/*If we reach 10 then x is 9*/
			if(x == 10){
				x--;
					
				/*Compute y*/
				mpz_mul_ui(y, p, 20U);
				mpz_add_ui(y, y, x);
				mpz_mul_ui(y, y, x);
			}

			/*Add x to the sum of digits and add a digit to the count*/
			sum += x;
			digits++;

			/*Compute p*/
			mpz_mul_ui(p, p, 10U);
			mpz_add_ui(p, p, x);

			/*Compute c*/
			mpz_sub(c, c, y);
			mpz_mul_ui(c, c, 100U);
		}
	}

	printf("%lu\n", sum);

	mpz_clear(p);
	mpz_clear(y);
	mpz_clear(c);
	
	return 0;
}
