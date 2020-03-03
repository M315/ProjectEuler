/*Its a generalization of problem 31*/
#include <stdio.h>
#include <stdlib.h>

int ctrl(int*, int);

int main(void){
	int target=100, ways[101], i, j;
	for(i=0; i<=100; i++){
		ways[i]=0;
	}
	ways[0]=1;
	
	for(i=1; i<=99; i++)
		for(j=i; j<=target; j++)
			ways[j]= ways[j]+ways[j-i];
	
	printf("%d\n", ways[100]);
	
	return 0;
}
