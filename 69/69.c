/*The program is not necesary to find the solution (see prj eul page for the smooth solution)*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n, n0, i, p[100000], np;
	double max=0, phi;
	
	for(n=2; n<=1000000; n=n+2){
		if(n==1.e5)
			printf("%d ", n);
		
		/*Find all the primes that divide n*/
		n0=n;
		np=0;
		i=2;
		while(n0>1){
			if(n0%i==0){
				p[np]=i;
				np++;
				n0=n0/i;
				/*printf("%d ", i);*/
			}
			while(n0%i==0)
				n0=n0/i;
			
			i++;
		}
		
		/*Calculate n/phi(n) with the Euler's product formula*/
		if(np==0){
			phi=((double)n)/(((double)n)-1.);
		}else{
			phi=1;
			for(i=0; i<np; i++)
				phi= phi/(1.-(1./((double)p[i])));
		}
		
		/*printf(" %g\n", phi);*/
		
		if(phi>max){
			max= phi;
			printf("%d\n", n);
		}
	}
	
	printf("\n%g\n", max);			
	
	return 0;
}
