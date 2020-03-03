#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primetest(long long int);

int main(void){
	int a, b;
	long long int n, p, max[2]={0,0};
	
	for(a=-1000; a<1000; a++){
		for(b=-1000; b<=1000; b++){
			n=0;
			do{
				p=n*n+a*n+b;
				n++;
			}while(primetest(p)==1 && p>0);
			
			if(n>=max[0]){
				max[0]=n;
				max[1]=a*b;
			}
		}
	}
	
	printf("**%lld %lld**\n", max[0], max[1]);
	
	return 0;
}

int primetest(long long int n){
	int i, s=((int)sqrt(n))+1;
	
	if(n%2==0){
		return 0;
	}
	if(n%3==0){
		return 0;
	}
	
	for(i=5; i<=s; i=i+2){
		if(n%i==0){
			return 0;
		}
	}
	
	return 1;
}
