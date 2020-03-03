#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int primecheck(int);

int main(void){
	int i, j, ns, s, bns=0, bs;
	
	clock_t begin = clock();
	
	/*Generate the list of first 5000 primes*/
	int plist[5000];
	plist[0]=2;
	i=3;
	j=1;
	while(j<5000){
		if(primecheck(i)==1){
			plist[j]=i;
			j++;
		}
		i=i+2;
	}
	
	/*Sum all consecutive primes from j till we reach a milli*/
	j=0;
	
	s=0;
	ns=-1;
	while(s<1000000){
		ns++;
		s= s+plist[ns+j];
	}
		
	do{		
		while(ns>bns){
			if(primecheck(s)==1){
				bs=s;
				bns=ns;
			}
			s= s-plist[j+ns];
			ns--;
		}
		
		j++;
		s=0;
		ns=-1;
		while(s<1000000){
			ns++;
			s= s+plist[ns+j];
		}
		
	}while(ns>bns);
	
	printf("\n%d, %d\n", bs, bns+1);
	
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	
	printf("\n%g s\n", time_spent);

	return 0;
}

int primecheck(int a){
	int n;
	if(a%2==0)
		return 0;
	for(n=3; n<=sqrt(a); n=n+2)
		if(a%n==0)
			return 0;
	return 1;
}
