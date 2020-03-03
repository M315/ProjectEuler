#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int i, s1=0, s2=0;
	
	for(i=1; i<101; i++){
		s1= s1+i;
		s2= s2+i*i;
	}
	
	printf("%d\n", s1*s1-s2);	
	
	return 0;
}

