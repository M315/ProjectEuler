#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n, m;
	int a, b, c, d;
	
	for(n=10; n<99; n++){
		b=n%10;
		a=n/10;
		
		for(m=n+1; m<100; m++){
			d=m%10;
			c=m/10;
			
			if(a==c && a!=0){
				if((n*d)==(m*b)){
					printf("#%d/%d\n", n, m);
				}
			}
			
			if(a==d && a!=0){
				if((n*c)==(m*b)){
					printf("#%d/%d\n", n, m);
				}
			}
			
			if(b==c && b!=0){
				if((n*d)==(m*a)){
					printf("#%d/%d\n", n, m);
				}
			}
			
			if(b==d && b!=0){
				if((n*c)==(m*a)){
					printf("#%d/%d\n", n, m);
				}
			}
			
		}
	}


	return 0;
}
