#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isNotHappy(long long int);

int main(void){
	long long int n, count = 0;

	for(n=2; n<10000000; n++){
		if(isNotHappy(n))
			count++;
	}

	printf("%lld\n", count);

	return 0;
}

bool isNotHappy(long long int n){
    int cycle[8] = {4,16,37,58,89,145,42,20};
	int i, d;
	long long int new;
    
    do{
		new = 0;
        while(n>0){
			d = n%10;
			new += d*d;
			n /= 10;
		}

		n = new;
        
        if(n==1){
            return false;
        }else{
            for(i=0; i<8; i++) 
                if(n == cycle[i])
                    return true;
        }
    }while(true);
}
