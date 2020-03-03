#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int b=0, c;
	double a, r;
	
	do{
		b++;
		a=(1.e6-2000.*((double)b))/(double)(2000.-2.*(double)b);
		r= a-(int)a;
	}while(r!=0);
	
	c= a*a+b*b;
		
	printf("%g %d %g,  prod=%g\n", a, b, sqrt(c), a*b*sqrt(c));	
	
	return 0;
}

