#include <stdio.h>
#include <stdlib.h>

int p(int, int);

int main(void){
	int a, j, c;
	
	for(a=2; a<=6; a++){
		c=0;
		for(j=a+1; j<101; j++)
			if(j%a==0)
				c++;
		printf("%d %d\n", a, c);
	}
	
	return 0;
}
			
