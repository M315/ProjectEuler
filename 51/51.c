#include <stdio.h>
#include <stdli.h>
#include <math.h>
#include <time.h>

int primecheck(int);

int main(void){
	
	
	
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
