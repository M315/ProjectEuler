#include <stdio.h>

int main(void){
	int s=2, k1=1, k2=2, aux;
	
	aux= k1+k2;
	k1= k2;
	k2= aux;
	
	while(k2<4*1.e6){
		if(k2%2==0)
			s=s+k2;
		aux= k1+k2;
		k1= k2;
		k2= aux;
	}	
	
	printf("%d\n",s);	
	
	return 0;
}

