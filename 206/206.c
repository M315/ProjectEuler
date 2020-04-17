#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_square(unsigned long long);
unsigned long long next_num(unsigned long long);

int main(void){
	unsigned long long num, aux = 0U;

	for(aux = 999999990; aux>=0; aux -= 10){
		num = next_num(aux);
		if(is_square(num))
			return 0;
	}

	return 0;
}

int is_square(unsigned long long num){
	unsigned long long sqr;

	sqr = (unsigned long long)floor(sqrt(num));
	if(sqr*sqr == num){
		printf("%llu\n", sqr);
		return 1;
	}

	return 0;
}

unsigned long long next_num(unsigned long long a){
	unsigned long long new, b = 123456789;
	unsigned long long int i = 1;

	new = 0;
	
	while(b > 0){
		i *= 10;
		new += (a%10)*i;
		a /= 10;

		i *= 10;
		new += (b%10)*i;
		b /= 10;
	}

	return new;
}
