/*
 * project euler 100
 *
 * Using https://oeis.org/A001653
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "gmp.h"

int main(void){
	unsigned long int k, count, a, b;
	mpz_t m, n, K;
	
	mpz_init(m);
	mpz_init(n);
	mpz_init(K);
	
	a = 1;
	b = 5;
	
	for(count = 3; count < 20; count++){
		k = 6*b - a; /*generates the numbers that we are looking for*/

		mpz_set_ui(K, k);
		
		/*Set K to k^2 - 1*/
		mpz_mul(K, K, K);
		mpz_sub_ui(K, K, 1U);

		/*Set K to 1 + 2K*/
		mpz_mul_ui(K, K, 2U);
		mpz_add_ui(K, K, 1U);

		/*Check if K is a perfect square*/
		if(mpz_perfect_square_p(K) != 0){
			mpz_sqrt(m, K);
			mpz_add_ui(m, m, 1);
			
			/*Check if m is divisible by 2*/
			if(mpz_mod_ui(n, m, 2U) == 0U){
				mpz_divexact_ui(m, m, 2U);

				mpz_set_ui(K, k);
				mpz_add_ui(n, K, 1U);
				mpz_divexact_ui(n, n, 2U);

				printf("#%lu:\t", count);
				gmp_printf ("n = %Zd,\t", n);
				gmp_printf ("m = %Zd,\t", m);
				gmp_printf ("K = %Zd.\n", K);
			}
		}

		a = b;
		b = k;
	}
	
	mpz_clear(m);
	mpz_clear(n);
	mpz_clear(K);
	
	return 0;
}
