/*Algortime dolent.
 * Hi ha d'haver-hi un algortime millor fent servir la facctoritzacio
 * del nombre en produccte de primers i usant combinatoria amb els seus
 * exponents*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n=1, i=2, d=1, k;
	
	while(d<500){
		n=n+i;
		i++;
		d=2;
		for(k=2; k<n/2; k++){
			if(n%k==0)
				d++;
		}
	}	

	printf("%d\n", n);
	
	return 0;
}

