#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n=999999, d=0, i;
	
	for(i=999; i>99; i--){
		if(n%i==0 && ((n/i)/1000)%10==0) d=i;
	}
	
	while(n>1 && d==0){		
		if((n/100)%10!=0){
			n=n-1100;
		}else{
			if((n/10)%10!=0){
				n=n-110;
			}else{	
				if(n%10!=0){
					n=n-11;
				}
			}
		}
		
		for(i=999; i>99; i--){
			if(n%i==0 && ((n/i)/1000)%10==0) d=i;
		}
	}	
	
	printf("%d, %d\n", n, d);	
	
	return 0;
}

