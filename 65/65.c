/*
 * project euler 65
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

int main(void){
	int k;
	unsigned long sum = 0;
	char *num;
	mpq_t c, x;
	
	mpq_init(c);
	mpq_init(x);
	
	mpq_set_ui(c, 0U, 1U);
	
	for(k=33; k>=1; k--){
		mpq_set_ui(x, 1U, 1U);
		mpq_add(c, x, c);
		mpq_canonicalize(c);
		/*mpq_out_str(stdout, 10, x);
		printf("\n");
		mpq_out_str(stdout, 10, c);
		printf("\n");*/
		
		mpq_inv(c, c);
		
		mpq_set_ui(x, 2U*k, 1U);
		mpq_add(c, x, c);
		mpq_canonicalize(c);

		mpq_inv(c, c);

		mpq_set_ui(x, 1U, 1U);
		mpq_add(c, x, c);
		mpq_canonicalize(c);
		
		mpq_inv(c, c);
	}
	
	mpq_set_ui(x, 2U, 1U);
	mpq_add(c, x, c);
	mpq_canonicalize(c);

	num = mpz_get_str(NULL, 10,  mpq_numref(c));
	
	for(k=0; k<strlen(num); k++)
		sum += (int)num[k] - 48;

	printf("%lu\n", sum);
	/*mpq_out_str(stdout, 10, c);
	printf("\n");*/

	free(num);
	mpq_clear(x);
	mpq_clear(c);
	
	return 0;
}
