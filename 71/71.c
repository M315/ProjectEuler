#include <stdio.h>
#include <stdlib.h>

int orderR(long long int, long long int, long long int, long long int);

int main(void){
	long long int n, d, bn=3, bd=8;
	
	for(n=4; n<430000; n++){
		if(n%3==0){
			n++;
		}
		
		d=((int)((7.*((double)n))/3.))+1;
		if(d>1000000){
			break;
		}
		
		/*printf("%lld, %lld\n", n, d);*/
		
		if(orderR(bn, bd, n, d)==1){
			bn= n;
			bd=d;
			/*printf("*%lld, %lld*\n", n, d);*/
		}
	}
	
	printf("\n%lld %lld\n", bn, bd);
	
	return 0;
}

int orderR(long long int n, long long int d, long long int n1, long long int d1){
	if(n*d1<d*n1){
		return 1;
	}else{
		if(n*d1==d*n1){
			return 0;
		}else{
			return -1;
		}
	}
}
