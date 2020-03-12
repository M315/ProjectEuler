/*
 * project euler 57
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct fraction{
	uint64_t a;
	uint64_t b;
}fraction;

int n_digits(uint64_t);
fraction sum_fractions(fraction, fraction);
uint64_t gcd(uint64_t, uint64_t);
uint64_t lcm(uint64_t, uint64_t);

int main(void){
	int k;
	fraction x, y, aux, s;
	
	x.a = 2;
	x.b = 1;
	
	y.a = 1;
	y.b = 2;
	
	for(k=100; k>1; k--){
		aux = sum_fractions(x,y);
		
		y.a = aux.b;
		y.b = aux.a;
		
		aux.a = 1;
		aux.b = 1;
		s = sum_fractions(aux,y);
		
		printf("%ld/%ld\n", s.a, s.b);
	}
	
	return 0;
}

int n_digits(uint64_t a){
	int n;
	uint64_t aux;
	
	aux = a;
	n = 0;
	while(aux!=0){
		n++;
		aux = aux/10;
	}
	
	return n;
}

fraction sum_fractions(fraction x, fraction y){
	fraction sum;
	
	sum.b = lcm(x.b, y.b);
	sum.a = x.a*(sum.b/x.b) + y.a*(sum.b/y.b);
	
	return sum;
}
	
uint64_t gcd(uint64_t a, uint64_t b){
	/*calculates the gcd using the euclid's algorithm*/
	uint64_t aux;
	
	while(b!=0){
		aux = b;
		b = a%b;
		a = aux;
	}
	
	return a;
}

uint64_t lcm(uint64_t a, uint64_t b){
	if(a == 0 || b == 0)
		return 0;
	
	if(a<0){
		if(b<0){
			return (a*b)/gcd(a,b);
		}else{
			return (-a*b)/gcd(a,b);
		}
	}else{
		if(b<0){
			return (-a*b)/gcd(a,b);
		}else{
			return (a*b)/gcd(a,b);
		}
	}
}
