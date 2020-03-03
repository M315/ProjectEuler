#include <stdio.h>

int main(void){
	long int i, j, n=1, sum=1;
	
	for(i=1; i<=500; i++){
		for(j=0; j<4; j++){
			n= n+2*i;
			sum= sum+n;
		}
	}
	
	printf("%ld\n", sum);
	
	return 0;
}
