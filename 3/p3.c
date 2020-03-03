#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	long int n=600851475143, mp=2;
	
	while(n!=1){
		if(n%mp==0){
			n=n/mp;
		}else{
			mp++;
		}
	}
	
	printf("%ld\n",mp);	
	
	return 0;
}

