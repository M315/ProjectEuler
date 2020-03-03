/*Programa inutil ja que nomes cal per el produccte de les maximes potencies
 *de tots els primers que apareixen en la descomposicio dels nombres enter 1 i 20
 * i.e. 19*17*13*11*7*5*9*16*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	int n=11*13*17*19;
	
	while(n%19!=0 ||n%18!=0 ||n%17!=0 ||n%16!=0 ||n%15!=0 ||n%14!=0 ||n%13!=0 ||n%11!=0)
		n++;
	
	printf("%d\n", n);	
	
	return 0;
}

