#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int oddprimetest(int);

int main(void){
	long int m=7, n, a;
	int ctrl=1;
	
	while(ctrl==1){
		m= m+2;
		ctrl=0;
		if(oddprimetest(m)==0){
			a= (int)sqrt((m-3)/2);
			for(n=1; n<=a; n++){
				if(oddprimetest(m-(2*n*n))==1){
					ctrl=1;
					break;
				}
			}
		}else{
			ctrl=1;
		}
	}
	
	printf("%ld\n", m);
	
	return 0;
}

int oddprimetest(int n){
	int i, a=((int)sqrt(n))+1;
	
	for(i=3; i<=a; i=i+2){
		if(n%i==0){
			return 0;
		}
	}
	
	return 1;
}
