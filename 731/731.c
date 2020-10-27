/*
 * Project Euler 731
 *
 * Given that for each new sumant in the series the digits start comming after 10^(3^i)
 * to compute the fisrt 10 digits after 10^16 we only need to know the digits of the fractions
 * until i = 31, cause 3^32 > 10^16.
 * 
 * Noting that every fraction that we face is a swifted (by 10^(3^i) digits) unit fraction of a
 * power of 3, and it's easy to see that every one of this have a period of 3^(i-2) except 3 and 9
 * that have period 1. The idea is to compute this periods using standard division algorithm
 * and then sum the digits of those after the given point (10^16), and not all of them just a few
 * hundred will do.
 *
 * Need to optimize the division algorithm and just store the 100 ~ 1000 digits that will be used in
 * the sum for every sumand.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct digit_expantion{
	long long int swift;
	long long int period;
	int *digit;
} d_exp;

int init_d_exp(d_exp*, int, long long int*);

int main(void){
	int i, max = 20;
	long long int n = 9;
	d_exp *t;

	t = (d_exp *)malloc(max * sizeof(d_exp));
		if(t == NULL){printf("Err: No Mem\n"); return 1;}

	/* Set the digit expantion of 3 and 9 */
	t[0].swift = 3;
	t[0].period = 1;
	t[0].digit = (int *)malloc(t[0].period * sizeof(int));
		if(t[0].digit == NULL){printf("Err: No Mem\n"); return 1;}
	t[0].digit[0] = 3;

	t[1].swift = 9;
	t[1].period = 1;
	t[1].digit = (int *)malloc(t[1].period * sizeof(int));
		if(t[1].digit == NULL){printf("Err: No Mem\n"); return 1;}
	t[1].digit[0] = 1;

	for(i = 2; i < max; i++)
		if(init_d_exp(t, i, &n))
			return 1;
		
	/*for(i = 0; i < max; i++)
		free(t[i].digit);*/
	
	return 0;
}

int init_d_exp(d_exp *t, int i, long long int *n){
	long long int k, div = 10, r = 0, q;
	
	t[i].period = *n / 3;
	*n *= 3;
	t[i].swift = *n;

	/*t[i].digit = (int *)malloc(t[i].period * sizeof(int));
		if(t[i].digit == NULL){ printf("Err: No Mem\n"); return 1;}*/
	
	for(k = 0; k < t[i].period; k++){
		if(div < *n){
			div *= 10; 
			/*t[i].digit[k] = 0;*/
		}else{
			q = div / *n;
			r = div - (*n * q);
			div = r * 10;

			/*t[i].digit[k] = q;*/
		}
	}

	/*printf("Digits of %lld: ", *n);
	for(k = 0; k < t[i].period; k++)
		printf("%d", t[i].digit[k]);
	printf("\n");*/
	
	printf("%lld\t\t->\t\t%lld,\t\t%lld\n", *n, t[i].swift, t[i].period);

	return 0;
}
