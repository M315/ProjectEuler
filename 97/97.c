/*
 * ProjectEuler 79
 */ 

#include <stdio.h>
#include <stdlib.h>

int main(void){
	unsigned long long res;
	int i;
	
	res = 1U;
	for(i=0; i<7830457; i++){
		res *= 2;
		res %= 10000000000;
	}
	
	res = (res*28433) % 10000000000;
	res++;
	
	printf("%llu\n", res);
	
	return 0;
}
