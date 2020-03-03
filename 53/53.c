#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(void){
	int sum=0, n, k;
	long int a;
	
	for(n=22; n<=100; n++){
		k=1;
		a=n;
		while(a<1000000 && k<((n/2)+1)){
			a= a*(n-k);
			a= a/(k+1);
			k++;
		}
		if(k<((n/2)+1) && n%2==0)
			sum= sum+(2*((n/2)-k+1))-1;
		if(k<((n/2)+1) && n%2!=0)
			sum= sum+(2*((n/2)-k+1));
	}
	
	printf("%d\n", sum);
	
	return 0;
}
