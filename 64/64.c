/*
* Project Euler 64
*
* WARNING: 	First aproch was using wikipedia algorithm with foating points
* 			that's inconvinient beacuse the operation 1/f makes us lose lots
*			of info every time its done and after 10 times aprox may lead to
*			isues
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int continued_fraction_period(int);
long long int gcd(long long int, long long int);

int main(void){
	int N, count = 0;
	
	for(N = 2; N < 10000; N++)
		if(continued_fraction_period(N) % 2 == 1)
			count++;
	
	printf("%d\n", count);
	
	return 0;
}

/*calculates de period of the continued fraction representing
* the sqrt of N
* Note: cont_frac misses the first digit of the sequence
* as it's needless to compute the period*/
int continued_fraction_period(int N){
	int *cont_frac, len = 0, i;
	long long int b, x, y, b_o, x_o, y_o, aux;

	if(N == (int)sqrt(N)*(int)sqrt(N))
		return 0;

	cont_frac = (int*)malloc(len*sizeof(int));
	
	/*see https://en.wikipedia.org/wiki/Continued_fraction#Calculating_continued_fraction_representations.
	* The notation stands for x / (y * sqrt(N) - b) */
	b = (int)sqrt(N);
	x = 1;
	y = 1;

	b_o = b;
	x_o = x;
	y_o = y;

	do{
		len++;
		
		cont_frac = (int*)realloc(cont_frac, len*sizeof(int));

		aux = (y * y * N) - (b * b);
		cont_frac[len-1] = (int)((double)x * ((sqrt(N) * y) + (double)b) / (double) aux);

		/*Compute the new values of x, y, and b*/
		y = x * y;
		b = (aux * cont_frac[len-1]) - x * b;
		x = aux;

		/*Reduce the values*/
		aux = gcd(b, y);
		aux = gcd(aux, x);
		b = b / aux;
		y = y / aux;
		x = x / aux;

		/*printf("#%d -> a = %d, b = %lld, x = %lld, y = %lld\n", len, cont_frac[len-1], b, x, y);*/
		/*period  = check_period(cont_frac, len);*/
	}while(b != b_o || y != y_o || x != x_o);

	/*printf("%d -> [%d; (", N, (int)sqrt(N));
	for(i = 0; i < len - 1; i++)
		printf("%d, ", cont_frac[i]); 
	printf("%d)]\n", cont_frac[i]);*/
	
	free(cont_frac);

	return len;
}

long long int gcd(long long int n, long long int m){
	long long int t;

	while(m != 0){
		t = m;
		m = n % m;
		n = t;
	}

	return n;
}
