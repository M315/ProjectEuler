#include <stdio.h>
#include <stdlib.h>

int p5(int);

int main(void){
	int n, n0, aux, sum=0;
	
	for(n=2; n<1.e6; n++){
		n0= n;
		aux=0;
		
		while(n0!=0){
			aux= aux+p5(n0%10);
			n0= n0/10;
		}
		
		if(n==aux){
			printf("%d\n", n);
			sum= sum+n;
		}
	}
	
	printf("\n%d\n", sum);
	
	return 0;
}

int p5(int n){
	return n*n*n*n*n;
}
