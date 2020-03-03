/*El programa agafa els valors de les monedes llavors calcula primer com podem pagar x
 * fent servir nomes monedes de 1p, depres calcula de quantes maneres podem pagar x sabent
 * que donem una moneda de kp, que es igual a les maneres de pagar x-k amb monesdes de valor kp o menys
 * que ja em calculat i ho sumem a les maneres que ja haviem calculat*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int coins[8]={1,2,5,10,20,50,100,200}, ways[201], target=200, i, j;
	
	ways[0]=1;
	for(i=1; i<=200; i++){
		ways[i]=0;
	}
	
	for(i=0; i<8; i++){
		for(j=coins[i]; j<=target; j++){
			ways[j]= ways[j]+ways[j-coins[i]];
		}
	}
	
	printf("%d\n", ways[200]);
	
	return 0;
}
	
