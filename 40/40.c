#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	unsigned long long int d=0, aux, p=1;
	int n=0, digit[7], c, nobj=10;
	
	clock_t begin = clock();
	
	while(n<(1.e6+1)){
		d++;
		aux= d;
		c= 0;
		while(aux>0){
			digit[c]= aux%10;
			c++;
			aux= aux/10;
		}
		if((n+c)>=nobj){
			p= p*digit[c-(nobj-n)];
			nobj= nobj*10;
		}
		n= n+c;
	}
	
	printf("%lld", p);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%g s\n", time_spent);
	
	return 0;
}
