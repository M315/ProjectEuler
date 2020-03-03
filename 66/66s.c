/*Solucionar el sistema calculant la part entera sqrt(D*y*y+1) amb l'algoritme de calcul darrels manual
 * pero es massa lent, tarda masa en evaluar totes les y per algunes D ja que necesiten mes de 1.e8 per trobar la solucio*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
	long D, x, y, Dy, aux, max=1, i, j, *a, c, r, p, px, py;
	
	for(D=2; D<1001; D++){
		
		if(D!=(((int)sqrt(D))*((int)sqrt(D)))){
			
			y=0;
			do{
				y++;
				Dy= D*y*y;
				aux= Dy+1;
				
				i=0;
				do{
					aux=aux/100;
					i++;
				}while(aux!=0);
				
				a=(long*)calloc(i, sizeof(long));
					if(a==NULL){printf("No Mem\n"); return -1;}
				
				aux= Dy+1;
				
				for(j=0; j<i; j++){
					a[i-j-1]= aux%100;
					aux= aux/100;
				}
				
				r=0;
				p=0;
				for(j=0; j<i; j++){
					c= r*100+a[j];
					
					px= 1;
					py= px*(20*p+px);
					
					while(py<=c){
						px++;
						py= px*(20*p+px);
					}
					px--;
					py= px*(20*p+px);
					p= p*10+px;
					
					r= c-py;
				}			
				
				x= p;
				
				free(a);
				
				if(y==1.e7){ printf("\n%ld...\n", D);} 
				
			}while(x*x-Dy!=1 && y<1.e8);
			
			
					
			if(x>max || y==1.e8-1){
				max=x;
				printf("%ld-> %ld %ld\n", D, x, y);
			}
		}			
	}
	
	printf("\n%ld\n\n", max);

	return 0;
}
