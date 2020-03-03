/*Trivial, just be carefull and use long int, cause with just using int
 *there's not enough mem for some numbers and the program doesnt converge.*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
	long int n, i, c, nmax=0, max=0, *nc;
	
	nc= (long int*)calloc(1.e6, sizeof(long int));
		if(nc==NULL){printf("No mem\n"); exit(-1);}
	
	nc[0]= 1;
	nc[1]= 2;
	
	for(n=3; n<=1.e6; n++){
		i= n;
		
		c= 0;
		while(i!=1){
			c++;
			if(i%2==0){
				i=i/2;
			}else{
				i=(3*i)+1;
			}
			if(i<n){
				c= c+nc[i-1];
				i=1;
			}
		}
		
		nc[n-1]= c;
		
		if(c>max){
			max= c;
			nmax= n;
		}
	}
	
	free(nc);
	
	printf("%ld %ld\n", nmax, max);

	return 0;
}
