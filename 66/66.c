/*Solucionar el sistema calculan la part entera de sqrt(1+D*y*y) usant la funcio sqrt()
 *no convergeix perque requereix de masa calculs i ames la funcio (double)=sqrt(double)
 * retorna un double amb un error per tant s'ha de tenir en compte*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	long D, x, y, Dy, Dif, max=1;
	
	for(D=2; D<101; D++){
		
		if(D!=(((int)sqrt(D))*((int)sqrt(D)))){
			
			y=1;
			do{
				Dy= D*y*y;
				
				x=(int)sqrt(D)*y;
					
				Dif= x*x-Dy;								
				while(Dif<1){
					x++;
					Dif= x*x-Dy;
				}
				
				if(Dif!=1)
					y++;
				
				/*if(y>1.e4){printf("\n%ld...\n\n", D);}*/
							
			}while(Dif!=1 && y<1.e5);
			
			
					
			if(x>max || y>1.e5-1){
				max=x;
				printf("%ld-> %ld %ld\n", D, x, y);
			}
		}			
	}
	
	printf("\n%ld\n\n", max);

	return 0;
}
