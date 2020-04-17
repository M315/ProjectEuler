/*
 * project euler 57
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gmp.h"

int main(void){
	int k, count = 0;
	unsigned long long len_num, len_den;
	mpq_t s, y, x, aux;
	/*mpz_t num, den;*/
	
	mpq_init(s);
	mpq_init(y);
	mpq_init(x);
	mpq_init(aux);
	
	mpq_set_ui(x, 2U, 1U);
	mpq_set_ui(y, 1U, 2U);
	
	for(k=0; k<1000; k++){
		mpq_add(aux, x, y);
		mpq_canonicalize(aux);
		
		mpq_inv(y, aux);
		
		mpq_set_ui(aux, 1U, 1U);
		mpq_add(s, aux, y);
		mpq_canonicalize(s);

		/*num = mpq_numref(s);
		den = mpq_denref(s);*/
		len_num = strlen(mpz_get_str(NULL, 10, mpq_numref(s)));
		len_den = strlen(mpz_get_str(NULL, 10, mpq_denref(s)));

		if(len_num > len_den)
			count++;
	}

	printf("%d\n", count);

	mpq_clear(s);
	mpq_clear(y);
	mpq_clear(x);
	mpq_clear(aux);
	
	return 0;
}
